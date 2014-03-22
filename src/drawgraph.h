#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include<QMap>
#include "graphicscreen.h"

struct Coordinate;

class DrawGraph
{
private:
    double radius;
    double nodeRadius;
    QMap<QString,Coordinate*> corMap;
    Coordinate centerScreen;
public:
    DrawGraph();
    template<typename Type>
        DrawGraph(Type, Type, int);
    void drawGraph();
};
struct Coordinate{
    double cor_X;
    double cor_Y;
};
#endif // DRAWGRAPH_H
