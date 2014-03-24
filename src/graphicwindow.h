#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QDialog>
#include <QPainter>
#include "graph.h"
#include "drawgraph.h"

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicWindow(QWidget *parent = 0);
    void setLand(Graph::vmap::const_iterator,
                 Graph::vmap::const_iterator,int);
    void paintEvent(QPaintEvent*);
    ~GraphicWindow();

private:
    Ui::GraphicWindow *ui;
    typedef QMap<QString,DrawGraph::Coordinate*>::iterator dmap;
protected:
    DrawGraph* land;

};

#endif // GRAPHICWINDOW_H
