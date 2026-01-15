#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "AksSystem.h"
#include "Simulators.h"
#include "launcherwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SimulatorWorker : public QObject {
    Q_OBJECT
public:
    SimulatorWorker() : m_running(true) {}
    void stop() { m_running = false; }

    void run() {
        Simulators sims;
        while (m_running) {
            sims.update();
            QThread::msleep(10);
        }
    }

private:
    volatile bool m_running;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void updateSystem();           // called by timer to update AKS
    void onSetTargetClicked();     // handle target button
    void onFireClicked();          // handle fire button
    void onMissileSelectionChanged(int index);  // handle missile selection
    void updateFiringCountdown();  // update firing countdown display

private:
    void updateConnectionLeds();
    void updatePositionDisplay();
    void updateMissileDisplay();
    void syncMissileStatesFromBackend();

    Ui::MainWindow* ui;
    AksSystem m_aks;
    LauncherWidget* m_launcherWidget;
    
    QTimer* m_updateTimer;       // main system update (100ms)
    QTimer* m_firingTimer;       // firing countdown (1s)
    int m_firingCountdown;       // seconds remaining
    int m_firingMissileIndex;    // which missile is firing
    
    // connection status 
    bool m_insConnected;
    bool m_launcherConnected;
    int m_missedIns;
    int m_missedLauncher;
    
    // simulator 
    QThread* m_simThread;
    SimulatorWorker* m_simWorker;
};

#endif 
