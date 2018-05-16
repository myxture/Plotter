QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Plotter
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += headers

SOURCES += \
        sources/qcustomplot.cpp \
        sources/main.cpp \
        sources/mainwindow.cpp \
        sources/function.cpp

HEADERS += \
        headers/qcustomplot.h \
        headers/mainwindow.h \
        headers/plotter.h \
        headers/function.h

FORMS += \
        forms/mainwindow.ui
