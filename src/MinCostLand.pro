#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T13:27:50
#           Burak KOSE
#               using Graph Algorithm and Graphics
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prolab2-1
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           graph.cpp \
           drawgraph.cpp \
           graphicwindow.cpp \
           disjointset.cpp

HEADERS  += mainwindow.h \
            graph.h \
            drawgraph.h \
            graphicwindow.h \
            disjointset.h

FORMS    += mainwindow.ui \
            graphicwindow.ui

OTHER_FILES +=

RESOURCES += \
            image.qrc
