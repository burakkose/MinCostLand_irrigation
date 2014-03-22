#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include <QMap>
#include <QString>

class DrawGraph
{
private:
    struct Coordinate{
        double cor_X;
        double cor_Y;
    };

public:
    DrawGraph(){}
    template<typename Type>
    DrawGraph(Type, Type, int);
    void drawGraph();

private:
    double radius;
    double nodeRadius;
    QMap<QString,Coordinate*> corMap;
    Coordinate centerScreen;
};

#endif // DRAWGRAPH_H
