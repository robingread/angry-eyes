#pragma once

#include "eye.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <memory>


class EyePair
{

public:
    EyePair(QGraphicsScene *scene);
    ~EyePair();

    std::unique_ptr<Eye> m_rightEye;
    std::unique_ptr<Eye> m_leftEye;

    int getEyeRadius() const;
    int getInterocularDistance() const;
    QPoint getEyePosition() const;

    bool setEyeRadius(const int &radius);
    bool setInterocularDistance(const int &distance);
    void setEyePosition(const QPoint &point);
    void setTopBrowThickness(const int &thickness) const;

private:
    int m_interocularDistance;
    int m_eyeRadius;
    QPoint m_center;

};
