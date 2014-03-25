#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include <QMap>
#include <QString>
#include "graph.h"

class DrawGraph
{
private:
    struct Coordinate{
        double cor_X;
        double cor_Y;
        int    area;

        Coordinate()
            :cor_X(0),cor_Y(0),
              area(-1){}

    };

public:
    DrawGraph(){}
    DrawGraph(Graph::vmap::const_iterator,
              Graph::vmap::const_iterator, int);
    void   drawGraph();
    double getBigRadius(){return radius;}
    double getNodeRadius(){return nodeRadius;}

private:
    double radius;
    double nodeRadius;

public:
    QMap<QString,Coordinate*> corMap;
    Graph::vmap cVertexMap; // Copy VertexMap
    Coordinate centerScreen;

};

#endif // DRAWGRAPH_H
