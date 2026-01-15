#ifndef MISSILEWIDGET_H
#define MISSILEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class MissileWidget : public QWidget {
    Q_OBJECT

public:
    enum State {
        Empty,      
        Healthy,   
        Unhealthy,  
        Fired       
    };

    explicit MissileWidget(int index, QWidget* parent = nullptr);

    void setState(State state);
    State getState() const { return m_state; }
    
    void setMissileName(const QString& name);
    QString getMissileName() const { return m_name; }
    
    void setPowered(bool powered);
    bool isPowered() const { return m_powered; }

    void setFiringProgress(int seconds); 

signals:
    void clicked(int index);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

private:
    int m_index;
    State m_state;
    QString m_name;
    bool m_powered;
    bool m_hovered;
    int m_firingProgress; 
};

#endif 
