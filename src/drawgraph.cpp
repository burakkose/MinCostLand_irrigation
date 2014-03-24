#include "drawgraph.h"
#include <QtMath>

const double PI = 3.141592653589793238463;

DrawGraph::DrawGraph(Graph::vmap::const_iterator begin
                     ,Graph::vmap::const_iterator end,
                     int keySize){
    centerScreen.cor_X    = 240;
    centerScreen.cor_Y    = 240;
    radius                = 200; //Circle Radius
    double angle          = 0.0;
    const double perAngle = 360.0 / keySize;
    nodeRadius            = radius * 2 * sin(qDegreesToRadians(perAngle / 2)) / 6;

    for(Graph::vmap::const_iterator it = begin ; it != end ; it++){
        double radianAngle = qDegreesToRadians(angle);
        Coordinate* cor = new Coordinate();

        cor->cor_X = centerScreen.cor_X + radius * sin(radianAngle);
        cor->cor_Y = centerScreen.cor_Y + radius * cos(radianAngle);

        corMap[it.key()] = cor;
        angle += perAngle;

    }
}
