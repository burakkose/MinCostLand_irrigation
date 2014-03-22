#include "drawgraph.h"
#include <QtMath>

const double PI = 3.141592653589793238463;

template<typename Type>
DrawGraph::DrawGraph(Type begin , Type end , int keySize){
    centerScreen.cor_X    = 240;
    centerScreen.cor_Y    = 240;
    radius                = 220; //Circle Radius
    double angle          = 0.0;
    const double perAngle = 360.0 / keySize;
    nodeRadius            = ( radius * 2 * sin(perAngle / 2.0) / 6);

    for(Type it = begin ; begin != end ; begin++){
        Coordinate* cor = new Coordinate();
        cor->cor_X = centerScreen.cor_X + radius * sin(angle);
        cor->cor_Y = centerScreen.cor_Y + radius * cos(angle);
        corMap[it.key()] = cor;
        angle += perAngle;
    }
}
