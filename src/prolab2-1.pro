#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T13:27:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prolab2-1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp \
    unionfind.cpp \
    drawgraph.cpp \
    graphicscreen.cpp

HEADERS  += mainwindow.h \
    graph.h \
    unionfind.h \
    drawgraph.h \
    graphicscreen.h

FORMS    += mainwindow.ui \
    graphicscreen.ui