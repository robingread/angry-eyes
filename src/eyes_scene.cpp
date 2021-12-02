#include "eyes_scene.h"
#include <iostream>

EyesScene::EyesScene()
{
    m_eyePair = std::make_unique<EyePair>(this);
}


EyesScene::~EyesScene()
{
}


void EyesScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    const int mouseX = event->lastScenePos().x();
    const int mouseY = event->lastScenePos().y();
    m_eyePair->setEyePosition(QPoint(mouseX, mouseY));
}


void EyesScene::mouseReleaseEvent(QGraphicsSceneMouseEvent */*event*/)
{
    const int x = this->sceneRect().center().x();
    const int y = this->sceneRect().center().y();
    m_eyePair->setEyePosition(QPoint(x, y));
}
