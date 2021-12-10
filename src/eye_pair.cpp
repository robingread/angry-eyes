#include "eye_pair.h"
#include <iostream>


EyePair::EyePair(QGraphicsScene *scene) : m_scene(scene)
{

    m_center = QPoint(scene->sceneRect().center().x(), scene->sceneRect().center().y());
    m_eyeRadius = 25;
    m_interocularDistance = 75;

    m_rightEye = std::make_unique<Eye>(scene, Eye::RIGHT);
    m_leftEye = std::make_unique<Eye>(scene, Eye::LEFT);

    setEyePosition(m_center);
}


EyePair::~EyePair()
{
}


void EyePair::setConfig(const FaceConfig &config)
{
    applyEyeConfig(m_leftEye, config.leftEye);
    applyEyeConfig(m_rightEye, config.rightEye);
    setInterocularDistance(m_scene->width() * config.interocularDistance.value);
}


int EyePair::getEyeRadius() const
{
    return m_eyeRadius;
}


int EyePair::getInterocularDistance() const
{
    return m_interocularDistance;
}


QPoint EyePair::getEyePosition() const
{
    return m_center;
}


bool EyePair::setEyeRadius(const int &radius)
{
    m_eyeRadius = radius;
    m_leftEye->setEyeRadius(radius);
    m_rightEye->setEyeRadius(radius);
    return true;
}


void EyePair::setInterocularDistance(const int &distance)
{
    m_interocularDistance = distance;
    setEyePosition(m_center);
}


void EyePair::setEyePosition(const QPoint &point)
{
    m_center = point;
    const int r = m_eyeRadius / 2;
    const int d = m_interocularDistance / 2;
    const int left_x = m_center.x() - d;
    const int left_y = m_center.y() - r;
    const int right_x = m_center.x() + d;
    const int right_y = m_center.y() - r;

    m_leftEye->setEyePosition(QPoint(left_x, left_y));
    m_rightEye->setEyePosition(QPoint(right_x, right_y));
}


void EyePair::applyEyeConfig(std::unique_ptr<Eye> &eye, const EyeConfig &config)
{
    const float scalar = 50;
    const float maxAngle = 45;

    const float eyeRadius = config.pupilRadius.value * scalar;
    const float bottomBrowThickness = config.bottomBrow.thickness.value * (eyeRadius * 2.0f);
    const float bottomBrowAngle = -maxAngle + (config.bottomBrow.angle.value * (maxAngle * 2.0));
    const float topBrowThickness = config.topBrow.thickness.value * (eyeRadius * 2.0f);
    const float topBrowAngle = -maxAngle + (config.topBrow.angle.value * (maxAngle * 2.0));

    eye->setEyeRadius(config.pupilRadius.value * scalar);
    eye->setBottomBrowThickness(bottomBrowThickness);
    eye->setBottomBrowAngle(bottomBrowAngle);
    eye->setTopBrowThickness(topBrowThickness);
    eye->setTopBrowAngle(topBrowAngle);
}
