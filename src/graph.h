#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QTextStream>

struct Vertex;

struct Edge{
    double cost;
    QString sourceName;
    QString destName;

    Edge(QString s = "",QString d = "" ,double a = 0.0)
        :sourceName(s),destName(d),cost(a){}

};

struct Vertex{
    QString name;
    QVector<Edge> adj;
    Vertex(const QString &nm)
        :name(nm){}

};

class Graph
{
    Vertex * getVertex( const QString &);

public:
    typedef QMap<QString,Vertex *> vmap;
    Graph();
    void addEdge( const QString &,
                  const QString &, double);
    void readFile(const QString &);
    void kruskal();
    ~Graph();

private:
    vmap vertexMap;

};

#endif // GRAPH_H
