QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = angry_eyes
TEMPLATE = app
CONFIG += c++17

INCLUDEPATH += include

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/eye_pair.cpp \
    src/eyes_scene.cpp \
    src/eye.cpp

HEADERS += include/mainwindow.h \
    include/data_model.h \
    include/eye_pair.h \
    include/eyes_scene.h \
    include/eye.h

FORMS += mainwindow.ui
