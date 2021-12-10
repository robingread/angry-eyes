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

    QPen pen(Qt::transparent);
    pen.setWidth(0);

    m_pupil = scene->addEllipse(0, 0, 0, 0, QPen(m_eyeColour), QBrush(m_eyeColour));
    m_topBrow = scene->addRect(0, 0, 0, 0, pen, QBrush(Qt::black));
    m_bottomBrow = scene->addRect(0, 0, 0, 0, pen, QBrush(Qt::black));
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
    const int browPadding = 2;
    const double browScalar = 1.05;
    const int r = m_eyeRadius;
    const int eyeWidth = m_eyeRadius * 2;
    const int pupilX = m_eyePos.x() - r;
    const int pupilY = m_eyePos.y() - r;
    m_pupil->setRect(pupilX, pupilY, eyeWidth, eyeWidth);

    const int topBrowX = pupilX - browPadding;
    const int topBrowY = pupilY - 1;
    const int topBrowWidth = eyeWidth + (browPadding * 2);
    const int topBrowHeight = m_topBrowThickness * browScalar;
    m_topBrow->setRect(topBrowX, topBrowY, topBrowWidth, topBrowHeight);
    m_topBrow->setTransformOriginPoint(m_eyePos.x(), m_eyePos.y());
    m_topBrow->setRotation(m_topBrowAngle);

    const int bottomBrowX = pupilX - browPadding;
    const int bottomBrowY = pupilY - 1;
    const int bottomBrowWidth = eyeWidth + (browPadding * 2);
    const int bottomBrowHeight = m_bottomBrowThickness * browScalar;
    m_bottomBrow->setRect(bottomBrowX, bottomBrowY, bottomBrowWidth, bottomBrowHeight);
    m_bottomBrow->setTransformOriginPoint(m_eyePos.x(), m_eyePos.y());
    m_bottomBrow->setRotation(m_bottomBrowAngle + 180);
}
