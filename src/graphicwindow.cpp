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
                            int keySize,QString &name){

    land      = new DrawGraph(begin,end,keySize);
    sNodeName = name;

}

void GraphicWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen penBegin , penLine;

    penBegin.setStyle(Qt::DotLine);
    penBegin.setColor(Qt::black);
    penLine.setStyle(Qt::SolidLine);
    penLine.setColor(Qt::darkRed);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(penBegin);

    double x = land->centerScreen.cor_X;
    double y = land->centerScreen.cor_Y;
    double r = land->getBigRadius();

    painter.drawEllipse(QPointF(x,y),r,r);

    Graph::vmap* pVertexMap = &land->cVertexMap;

    for(dmap it = land->corMap.begin() ; it !=land->corMap.end();++it){

        painter.setPen(penLine);
        painter.setBrush(Qt::darkBlue);

        QString nodeName = it.key();

        x = it.value()->cor_X;
        y = it.value()->cor_Y;
        r = land->getNodeRadius();

        for(QVector<Edge>::iterator ite = pVertexMap->value(nodeName)->adj.begin();
            ite != pVertexMap->value(nodeName)->adj.end();ite++){

            QString destNodeName = ite->destName;

            double x2 = land->corMap.value(destNodeName)->cor_X;
            double y2 = land->corMap.value(destNodeName)->cor_Y;

            painter.drawLine(QPointF(x,y),QPointF(x2,y2)); // draw connection

            double x3 = (x + x2) / 2;
            double y3 = (y + y2) / 2;

            painter.drawText(QPointF(x3,y3),QString::number(ite->cost));
        }

        if(nodeName == sNodeName) // for special node
            painter.setBrush(Qt::darkCyan);

        painter.drawEllipse(QPointF(x,y),r,r); //draw node

        painter.setPen(Qt::yellow);
        painter.drawText(QPointF(x,y),nodeName);
    }
}
GraphicWindow::~GraphicWindow()
{
    delete ui;

}
