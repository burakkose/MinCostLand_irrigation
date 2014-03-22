#include "graphicscreen.h"
#include "ui_graphicscreen.h"

#include <QGraphicsView>

GraphicScreen::GraphicScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicScreen)
{
    ui->setupUi(this);
}

GraphicScreen::~GraphicScreen()
{
    delete ui;
}
