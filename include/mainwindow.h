#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <memory>

#include "data_model.h"
#include "eye_pair.h"
#include "eyes_scene.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    FaceConfig m_data;

    Ui::MainWindow *ui;
    EyesScene *m_graphicsScene;
    QGraphicsEllipseItem *m_rightEye;
    QGraphicsEllipseItem *m_leftEye;

private slots:
    void onEyeRadiusValue(const int &value);
    void onInterocularDistanceValue(const int &value);
    void onTopBrowThickenssValue(const int &value);
    void onBottomBrowThickenssValue(const int &value);
    void onTopBrowAngleValue(const int &value);
    void onBottomBrowAngleValue(const int &value);
};
