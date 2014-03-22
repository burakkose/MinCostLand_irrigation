#include "graphicwindow.h"
#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);
}

template<typename Type>
void GraphicWindow::setLand(Type begin , Type end , int keySize){
    land = new DrawGraph(begin,end,keySize);

}

void GraphicWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
}

GraphicWindow::~GraphicWindow()
{
    delete ui;

}
