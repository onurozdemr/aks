#include "missilewidget.h"
#include <QPainterPath>

MissileWidget::MissileWidget(int index, QWidget* parent)
    : QWidget(parent)
    , m_index(index)
    , m_state(Empty)
    , m_name("")
    , m_powered(false)
    , m_hovered(false)
    , m_firingProgress(0)
{
    setMinimumSize(80, 80);
    setMaximumSize(80, 80);
    setCursor(Qt::PointingHandCursor);
    setMouseTracking(true);
}

void MissileWidget::setState(State state) {
    m_state = state;
    update();
}

void MissileWidget::setMissileName(const QString& name) {
    m_name = name;
    update();
}

void MissileWidget::setPowered(bool powered) {
    m_powered = powered;
    update();
}

void MissileWidget::setFiringProgress(int seconds) {
    m_firingProgress = seconds;
    update();
}

void MissileWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    int diameter = qMin(width(), height()) - 10;
    int x = (width() - diameter) / 2;
    int y = (height() - diameter) / 2;
    QRectF circleRect(x, y, diameter, diameter);
    
    QColor fillColor;
    switch (m_state) {
        case Healthy:
            fillColor = QColor("#a6e3a1"); // green
            break;
        case Unhealthy:
            fillColor = QColor("#f38ba8"); // red
            break;
        case Fired:
            fillColor = QColor("#6c7086"); // gray
            break;
        case Empty:
        default:
            fillColor = QColor("#1e1e2e"); //empty
            break;
    }
    
    painter.setBrush(fillColor);
    
    QPen borderPen;
    if (m_powered) {
        borderPen = QPen(QColor("#f9e2af"), 4); 
    } else {
        borderPen = QPen(QColor("#11111b"), 2); 
    }
    
  
    if (m_hovered && m_state == Healthy && !m_powered) {
        borderPen = QPen(QColor("#89b4fa"), 3); 
    }
    
    painter.setPen(borderPen);
    painter.drawEllipse(circleRect);
    
    if (!m_name.isEmpty()) {
        painter.setPen(QColor("#1e1e2e")); 
        QFont font = painter.font();
        font.setBold(true);
        font.setPointSize(12);
        painter.setFont(font);
        painter.drawText(circleRect, Qt::AlignCenter, m_name);
    }
    
    if (m_firingProgress > 0 && m_firingProgress <= 10) {
        painter.setPen(QColor("#fab387")); 
        QFont font = painter.font();
        font.setPointSize(9);
        painter.setFont(font);
        QString countdown = QString("%1s").arg(10 - m_firingProgress);
        painter.drawText(circleRect.adjusted(0, 25, 0, 0), Qt::AlignCenter, countdown);
    }
}

void MissileWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked(m_index);
    }
}

void MissileWidget::enterEvent(QEnterEvent* event) {
    Q_UNUSED(event);
    m_hovered = true;
    update();
}

void MissileWidget::leaveEvent(QEvent* event) {
    Q_UNUSED(event);
    m_hovered = false;
    update();
}
