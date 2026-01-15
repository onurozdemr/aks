#include "launcherwidget.h"
#include <QVBoxLayout>

LauncherWidget::LauncherWidget(QWidget* parent)
    : QWidget(parent)
    , m_selectedIndex(-1)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(15);
    
    m_launcherLabel = new QLabel("LANÇER", this);
    m_launcherLabel->setAlignment(Qt::AlignCenter);
    m_launcherLabel->setStyleSheet(
        "background-color: #45475a; "
        "color: #cdd6f4; "
        "padding: 10px; "
        "border-radius: 6px; "
        "font-size: 14px; "
        "font-weight: bold;"
    );
    m_launcherLabel->setMinimumHeight(40);
    mainLayout->addWidget(m_launcherLabel);
    
    QHBoxLayout* missilesLayout = new QHBoxLayout();
    missilesLayout->setSpacing(20);
    missilesLayout->setAlignment(Qt::AlignCenter);
    
    for (int i = 0; i < 4; i++) {
        m_missiles[i] = new MissileWidget(i, this);
        connect(m_missiles[i], &MissileWidget::clicked, 
                this, &LauncherWidget::onMissileClicked);
        missilesLayout->addWidget(m_missiles[i]);
    }
    
    mainLayout->addLayout(missilesLayout);
}

void LauncherWidget::setMissileState(int index, MissileWidget::State state) {
    if (index >= 0 && index < 4) {
        m_missiles[index]->setState(state);
    }
}

void LauncherWidget::setMissileName(int index, const QString& name) {
    if (index >= 0 && index < 4) {
        m_missiles[index]->setMissileName(name);
    }
}

void LauncherWidget::setMissilePowered(int index, bool powered) {
    if (index >= 0 && index < 4) {
        m_missiles[index]->setPowered(powered);
        if (powered) {
            m_selectedIndex = index;
        } else if (m_selectedIndex == index) {
            m_selectedIndex = -1;
        }
    }
}

void LauncherWidget::setMissileFiringProgress(int index, int seconds) {
    if (index >= 0 && index < 4) {
        m_missiles[index]->setFiringProgress(seconds);
    }
}

int LauncherWidget::getPoweredMissileIndex() const {
    return m_selectedIndex;
}

bool LauncherWidget::canSelectMissile(int index) const {
    if (index < 0 || index >= 4) return false;
    
    MissileWidget::State state = m_missiles[index]->getState();
    return (state == MissileWidget::Healthy);
}

void LauncherWidget::onMissileClicked(int index) {
    emit missileClicked(index);
    
    // Toggle selection logic
    if (!canSelectMissile(index)) {
        return; // Can't select unhealthy/empty/fired missiles
    }
    
    if (m_selectedIndex == index) {
        // Deselect (power off)
        m_missiles[index]->setPowered(false);
        m_selectedIndex = -1;
    } else {
        // Deselect previous
        if (m_selectedIndex >= 0 && m_selectedIndex < 4) {
            m_missiles[m_selectedIndex]->setPowered(false);
        }
        // Select new
        m_missiles[index]->setPowered(true);
        m_selectedIndex = index;
    }
    
    emit missileSelectionChanged(m_selectedIndex);
}
