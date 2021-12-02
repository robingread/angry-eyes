#pragma once

#include <memory>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>


class Eye : public QObject
{
    Q_OBJECT

public:

    enum Side {
        LEFT,
        RIGHT
    };

    explicit Eye(QGraphicsScene *scene, const Side &side);
    void draw();
    void setEyePosition(const QPoint &pos);
    void setEyeRadius(const int &radius);
    void setTopBrowThickness(const int &thickness);
    void setBottomBrowThickness(const int &thickness);
    void setTopBrowAngle(const int &angle);
    void setBottomBrowAngle(const int &angle);

private:
    Side m_eyeSide;
    QPoint m_eyePos;
    int m_eyeRadius;
    int m_topBrowThickness;
    int m_bottomBrowThickness;
    int m_topBrowAngle;
    int m_bottomBrowAngle;
    QColor m_eyeColour;
    QGraphicsEllipseItem *m_pupil;
    QGraphicsRectItem *m_topBrow;
    QGraphicsRectItem *m_bottomBrow;

};
