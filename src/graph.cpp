#include "graph.h"
#include "disjointset.h"
#include "graphicwindow.h"
#include <QtAlgorithms>

QString str_split(QString &str,char delim){

    QStringList temp;

    temp = str.split(delim);
    str  = temp.at(1);

    return temp.first();

}

bool sortEdges(const Edge &e1 , const Edge &e2){
    return e1.cost < e2.cost ;

}

Graph::Graph()
{
}

Graph::~Graph()
{
    for(vmap::iterator itr = vertexMap.begin();
        itr != vertexMap.end() ; ++itr)
        delete itr.value();

}

Vertex *Graph::getVertex(const QString &vertexName){
    vmap::iterator itr = vertexMap.find(vertexName);

    if(itr == vertexMap.end()){
        Vertex *nvertex = new Vertex(vertexName);
        vertexMap[vertexName] = nvertex;
        return nvertex;
    }

    return itr.value();

}

void Graph::addEdge(const QString &sourceName, const QString &destName, double cost){
    Vertex *v = getVertex(sourceName);
    Vertex *w = getVertex(destName);
    v->adj.push_back(Edge(v->name,w->name,cost));

}
void Graph::readWrite(const QString &fileLoca){
    QFile inFile(fileLoca);

    if(inFile.open(QIODevice::ReadWrite | QIODevice::Text)){

        QTextStream in(&inFile);
        source = in.readLine();
        while(!in.atEnd()){
            QString v,m;
            QString line = in.readLine();
            double price;
            v = str_split(line,'-');
            m = str_split(line,':');
            price = line.toDouble();
            this->addEdge(v,m,price);
        }

        in << endl << "cost : " << kruskal();
        inFile.close();

    }

}

double Graph::kruskal(){
    QVector <Edge> c_adj;
    for(vmap::iterator it = vertexMap.begin() ; it != vertexMap.end() ; it++){
        for(QVector <Edge>::iterator tor = it.value()->adj.begin() ; tor !=it.value()->adj.end() ; ++tor)
            c_adj.push_back(*tor);
    }

    qSort(c_adj.begin(),c_adj.end(),sortEdges);

    QMap<QString,DisJointSet::Node*> nodes;
    DisJointSet solve(vertexMap.begin(),vertexMap.end(),nodes);
    double cost = 0;

    while(c_adj.size() > 0){
        QString source = c_adj.begin()->sourceName;
        QString dest   = c_adj.begin()->destName;
        if(solve.find(nodes[source]) != solve.find(nodes[dest])){
            solve.merge(nodes[source],nodes[dest]);
            cost += c_adj.begin()->cost;
        }

        c_adj.pop_front();

    }

    return cost;

}
void Graph::drawGraph(){
    GraphicWindow screen;

    screen.setLand(vertexMap.cbegin(),
                   vertexMap.cend(),
                   vertexMap.size(),
                   source);

    screen.exec(); // show

}
