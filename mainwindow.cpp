#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_firingCountdown(0)
    , m_firingMissileIndex(-1)
    , m_insConnected(false)
    , m_launcherConnected(false)
    , m_missedIns(5)
    , m_missedLauncher(5)
{
    
    ui->setupUi(this);
    
    m_launcherWidget = new LauncherWidget(this);
    ui->launcherLayout->addWidget(m_launcherWidget);
    
    syncMissileStatesFromBackend();
    
    connect(ui->setTargetButton, &QPushButton::clicked, 
            this, &MainWindow::onSetTargetClicked);
    connect(ui->fireButton, &QPushButton::clicked, 
            this, &MainWindow::onFireClicked);
    connect(m_launcherWidget, &LauncherWidget::missileSelectionChanged,
            this, &MainWindow::onMissileSelectionChanged);
    
    m_updateTimer = new QTimer(this);
    connect(m_updateTimer, &QTimer::timeout, this, &MainWindow::updateSystem);
    m_updateTimer->start(100);
    
    m_firingTimer = new QTimer(this);
    connect(m_firingTimer, &QTimer::timeout, this, &MainWindow::updateFiringCountdown);
    
    m_simThread = new QThread(this);
    m_simWorker = new SimulatorWorker();
    m_simWorker->moveToThread(m_simThread);
    connect(m_simThread, &QThread::started, m_simWorker, &SimulatorWorker::run);

    
    connect(m_simThread, &QThread::finished, m_simWorker, &QObject::deleteLater);
    m_simThread->start();
}

MainWindow::~MainWindow() {
    m_simWorker->stop();
    m_simThread->quit();
    m_simThread->wait();
    delete ui;
}

void MainWindow::updateSystem() {
    m_aks.update();
    
    updateConnectionLeds();
    updatePositionDisplay();
    updateMissileDisplay();
}

void MainWindow::updateConnectionLeds() {

    bool insConnected = m_aks.isInsConnected();
    bool launcherConnected = m_aks.isLauncherConnected();
    

    if (insConnected) {
        ui->ansLed->setStyleSheet("background-color: #a6e3a1; border-radius: 12px;"); // Green
    } else {
        ui->ansLed->setStyleSheet("background-color: #f38ba8; border-radius: 12px;"); // Red
    }

    if (launcherConnected) {
        ui->launcherLed->setStyleSheet("background-color: #a6e3a1; border-radius: 12px;"); // Green
    } else {
        ui->launcherLed->setStyleSheet("background-color: #f38ba8; border-radius: 12px;"); // Red
    }
}

void MainWindow::updatePositionDisplay() {

    static double lat = 30.0, lon = 40.0, alt = 100.0;
    static auto lastUpdate = std::chrono::steady_clock::now();
    
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count() >= 1000) {
        lat += 1.0;
        lon += 1.0;
        lastUpdate = now;
    }
    
    ui->latitudeDisplay->setText(QString::number(lat, 'f', 2));
    ui->longitudeDisplay->setText(QString::number(lon, 'f', 2));
    ui->altitudeDisplay->setText(QString::number(alt, 'f', 2));
}

void MainWindow::updateMissileDisplay() {
    const auto& objects = m_aks.getObjManager().getObjects();
    
    for (int i = 0; i < 4; i++) {
        const auto& obj = objects[i];
        
        MissileWidget::State state;
        if (obj.isFired) {
            state = MissileWidget::Fired;
        } else if (!obj.isConnected) {
            state = MissileWidget::Empty;
        } else if (obj.isHealthy) {
            state = MissileWidget::Healthy;
        } else {
            state = MissileWidget::Unhealthy;
        }
        
        m_launcherWidget->setMissileState(i, state);
        m_launcherWidget->setMissileName(i, QString::fromStdString(obj.name));
    }
}

void MainWindow::syncMissileStatesFromBackend() {
    updateMissileDisplay();
}

void MainWindow::onSetTargetClicked() {
    TargetInfo target;
    target.latitude = ui->targetLatInput->text().toDouble();
    target.longitude = ui->targetLonInput->text().toDouble();
    target.altitude = ui->targetAltInput->text().toDouble();
    target.speed = ui->targetSpeedInput->text().toDouble();
    target.distance = ui->targetDistanceInput->text().toDouble();
    
    m_aks.getObjManager().setTargetInfo(target);
    
    ui->setTargetButton->setText("✓ Hedef Ayarlandı");
    QTimer::singleShot(2000, this, [this]() {
        ui->setTargetButton->setText("Hedef Bilgilerini Ayarla");
    });
}

void MainWindow::onMissileSelectionChanged(int index) {
    if (index >= 0) {
        m_aks.getObjManager().powerOn(index);
        ui->fireButton->setEnabled(true);
    } else {
        for (int i = 0; i < 4; i++) {
            m_aks.getObjManager().powerOff(i);
        }
        ui->fireButton->setEnabled(false);
    }
}

void MainWindow::onFireClicked() {
    int selectedIndex = m_launcherWidget->getPoweredMissileIndex();
    if (selectedIndex < 0) return;
    
    m_aks.getObjManager().fire(selectedIndex);
    
    m_firingMissileIndex = selectedIndex;
    m_firingCountdown = 0;
    
    ui->fireButton->setEnabled(false);
    ui->fireButton->setText("Ateşleniyor...");
    
    m_firingTimer->start(1000);
}

void MainWindow::updateFiringCountdown() {
    m_firingCountdown++;
    
    m_launcherWidget->setMissileFiringProgress(m_firingMissileIndex, m_firingCountdown);
    
    ui->fireButton->setText(QString("Ateşleniyor... %1s").arg(10 - m_firingCountdown));
    
    if (m_firingCountdown >= 10) {
        m_firingTimer->stop();
        
        m_launcherWidget->setMissileFiringProgress(m_firingMissileIndex, 0);
        m_launcherWidget->setMissileState(m_firingMissileIndex, MissileWidget::Fired);
        m_launcherWidget->setMissilePowered(m_firingMissileIndex, false);
        
        ui->fireButton->setText("ATEŞLE");
        
        m_firingMissileIndex = -1;
        m_firingCountdown = 0;
        
        updateMissileDisplay();
    }
}
