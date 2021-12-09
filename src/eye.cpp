#include "eye.h"
#include <iostream>
#include <qmath.h>


Eye::Eye(QGraphicsScene *scene, const Side &side) : QObject(scene)
{
    m_eyeSide = side;
    m_eyeRadius = 25;
    m_topBrowThickness = 10;
    m_bottomBrowThickness = 10;
    m_topBrowAngle = 0;
    m_bottomBrowAngle = 0;
    m_eyeColour = Qt::darkMagenta;

    m_pupil = scene->addEllipse(0, 0, 0, 0, QPen(m_eyeColour), QBrush(m_eyeColour));
    m_topBrow = scene->addRect(0, 0, 0, 0, QPen(Qt::black), QBrush(Qt::black));
    m_bottomBrow = scene->addRect(0, 0, 0, 0, QPen(Qt::black), QBrush(Qt::black));
}


void Eye::setEyePosition(const QPoint &pos)
{
    m_eyePos = pos;
    draw();
}


void Eye::setEyeRadius(const int &radius)
{
    m_eyeRadius = radius;
    draw();
}


void Eye::setTopBrowThickness(const int &thickness)
{
    m_topBrowThickness = thickness;
    draw();
}


void Eye::setBottomBrowThickness(const int &thickness)
{
    m_bottomBrowThickness = thickness;
    draw();
}


void Eye::setTopBrowAngle(const int &angle)
{
    int s = 1;
    if (m_eyeSide == Eye::LEFT)
    {
        s *= -1;
    }
    m_topBrowAngle = (90 * s) + (angle * s);
    draw();
}


void Eye::setBottomBrowAngle(const int &angle)
{
    int s = 1;
    if (m_eyeSide == Eye::LEFT)
    {
        s *= -1;
    }
    m_bottomBrowAngle = (90 * s) + (angle * s);
    draw();
}


void Eye::draw()
{
    const int r = m_eyeRadius;
    const int pupilX = m_eyePos.x() - r;
    const int pupilY = m_eyePos.y() - r;
    m_pupil->setRect(pupilX, pupilY, m_eyeRadius * 2, m_eyeRadius * 2);

    const int topBrowX = pupilX;
    const int topBrowY = pupilY;
    m_topBrow->setRect(topBrowX, topBrowY, m_eyeRadius * 2, m_topBrowThickness);
    m_topBrow->setTransformOriginPoint(m_eyePos.x(), m_eyePos.y());
    m_topBrow->setRotation(m_topBrowAngle);

    const int bottomBrowX = pupilX;
    const int bottomBrowY = pupilY + (2 * m_eyeRadius) - m_bottomBrowThickness;
    m_bottomBrow->setRect(bottomBrowX, bottomBrowY, m_eyeRadius * 2, m_bottomBrowThickness);
    m_bottomBrow->setTransformOriginPoint(m_eyePos.x(), m_eyePos.y());
    m_bottomBrow->setRotation(m_bottomBrowAngle);
}
