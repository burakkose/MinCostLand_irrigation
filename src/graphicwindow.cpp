#include "graphicwindow.h"
#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);
}

void GraphicWindow::setLand(Graph::vmap::const_iterator begin,
                            Graph::vmap::const_iterator end,
                            int keySize){
    land = new DrawGraph(begin,end,keySize);
}

void GraphicWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen penBegin , penLine;

    penBegin.setStyle(Qt::DotLine);
    penBegin.setColor(Qt::blue);
    penLine.setStyle(Qt::SolidLine);
    penLine.setColor(Qt::darkBlue);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(penBegin);

    double x = land->centerScreen.cor_X;
    double y = land->centerScreen.cor_Y;
    double r = land->getBigRadius();

    painter.drawEllipse(QPoint(x,y),r,r);

    painter.setPen(penLine);
    painter.setBrush(Qt::darkRed);

    Graph::vmap* pVertexMap = &land->cVertexMap;

    for(dmap it = land->corMap.begin() ; it !=land->corMap.end();++it){
        QString nodeName = it.key();

        x = it.value()->cor_X;
        y = it.value()->cor_Y;
        r = land->getNodeRadius();

        for(QVector<Edge>::iterator ite = pVertexMap->value(nodeName)->adj.begin();
            ite != pVertexMap->value(nodeName)->adj.end();ite++){

            QString destNodeName = ite->destName;
            double x2 = land->corMap.value(destNodeName)->cor_X;
            double y2 = land->corMap.value(destNodeName)->cor_Y;
            painter.drawLine(QPoint(x,y),QPoint(x2,y2)); // draw connection

        }

        painter.drawEllipse(QPoint(x,y),r,r); //draw node
        //painter.drawText(QPoint(x,y),nodeName);
    }
}

GraphicWindow::~GraphicWindow()
{
    delete ui;

}
