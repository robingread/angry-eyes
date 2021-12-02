#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "eye_pair.h"
#include <memory>


class EyesScene : public QGraphicsScene
{
    Q_OBJECT

public:
    std::unique_ptr<EyePair> m_eyePair;

    EyesScene();
    ~EyesScene();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
