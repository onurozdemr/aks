#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "missilewidget.h"

class LauncherWidget : public QWidget {
    Q_OBJECT

public:
    explicit LauncherWidget(QWidget* parent = nullptr);

    void setMissileState(int index, MissileWidget::State state);
    void setMissileName(int index, const QString& name);
    void setMissilePowered(int index, bool powered);
    void setMissileFiringProgress(int index, int seconds);
    
    int getPoweredMissileIndex() const;
    
    bool canSelectMissile(int index) const;

signals:
    void missileClicked(int index);
    void missileSelectionChanged(int index); 

private slots:
    void onMissileClicked(int index);

private:
    QLabel* m_launcherLabel;
    MissileWidget* m_missiles[4];
    int m_selectedIndex;
};

#endif 
