﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBrush>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_graphicsScene = new EyesScene();
    ui->graphicsView->setScene(m_graphicsScene);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    m_graphicsScene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    const int eyesX = m_graphicsScene->sceneRect().center().x();
    const int eyesY = m_graphicsScene->sceneRect().center().y();
    m_graphicsScene->m_eyePair->setEyePosition(QPoint(eyesX, eyesY));

    connect(ui->eyeRadiusSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onEyeRadiusValue(int)));

    connect(ui->interocularDistanceSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onInterocularDistanceValue(int)));

    connect(ui->topBrowThicknessSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onTopBrowThickenssValue(int)));

    connect(ui->bottomBrowThicknessSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onBottomBrowThickenssValue(int)));

    connect(ui->topBrowAngleSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onTopBrowAngleValue(int)));

    connect(ui->bottomBrowAngleSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onBottomBrowAngleValue(int)));

    ui->interocularDistanceSlider->setValue(99);
    ui->eyeRadiusSlider->setValue(30);
    ui->topBrowThicknessSlider->setValue(0);
    ui->bottomBrowThicknessSlider->setValue(10);
    ui->topBrowAngleSlider->setValue(0);
    ui->bottomBrowAngleSlider->setValue(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onEyeRadiusValue(const int &value)
{
    const QString s = "Eye Radius: " + QString::number(value);
    ui->eyeRadiusLabel->setText(s);

    const float radius = float(value) / float(ui->eyeRadiusSlider->maximum());
    m_data.leftEye.pupilRadius.value = float(radius);
    m_data.rightEye.pupilRadius.value = float(radius);
    m_graphicsScene->m_eyePair->setConfig(m_data);
}


void MainWindow::onInterocularDistanceValue(const int &value)
{
    const QString s = "Interocular Distance: " + QString::number(value);
    ui->interocularDistanceLabel->setText(s);

    const float val = float(value) / float(ui->interocularDistanceSlider->maximum());
    m_data.interocularDistance.value = val;
    m_graphicsScene->m_eyePair->setConfig(m_data);
}


void MainWindow::onTopBrowThickenssValue(const int &value)
{
    const QString s = "Top Brow Thickness: " + QString::number(value);
    ui->topBrowThicknessLabel->setText(s);

    const float val = float(value) / float(ui->topBrowThicknessSlider->maximum());
    m_data.leftEye.topBrow.thickness.value = val;
    m_data.rightEye.topBrow.thickness.value = val;
    m_graphicsScene->m_eyePair->setConfig(m_data);
}


void MainWindow::onBottomBrowThickenssValue(const int &value)
{
    const QString s = "Bottom Brow Thickness: " + QString::number(value);
    ui->bottomBrowThicknessLabel->setText(s);

    const float val = float(value) / float(ui->bottomBrowThicknessSlider->maximum());
    m_data.leftEye.bottomBrow.thickness.value = val;
    m_data.rightEye.bottomBrow.thickness.value = val;
    m_graphicsScene->m_eyePair->setConfig(m_data);
}


void MainWindow::onTopBrowAngleValue(const int &value)
{
    const QString s = "Top Brow Angle: " + QString::number(value);
    ui->topBowAngleLabel->setText(s);

    const float range = float(ui->topBrowAngleSlider->maximum() - ui->topBrowAngleSlider->minimum());
    const float val = float(ui->topBrowAngleSlider->minimum() + value) / range;
    m_data.leftEye.topBrow.angle.value = val;
    m_data.rightEye.topBrow.angle.value = val;
    m_graphicsScene->m_eyePair->setConfig(m_data);
}


void MainWindow::onBottomBrowAngleValue(const int &value)
{
    const QString s = "Bottom Brow Angle: " + QString::number(value);
    ui->bottomBrowAngleLabel->setText(s);

    const float range = float(ui->bottomBrowAngleSlider->maximum() - ui->bottomBrowAngleSlider->minimum());
    const float val = float(ui->bottomBrowAngleSlider->minimum() + value) / range;
    m_data.leftEye.bottomBrow.angle.value = val;
    m_data.rightEye.bottomBrow.angle.value = val;
    m_graphicsScene->m_eyePair->setConfig(m_data);
}
