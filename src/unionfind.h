#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "graph.h"

class UnionFind
{
private:
    class Node{
    public:
        int height;
        Node* parent;
        Node():height(0),parent(this){}
    };
public:
    UnionFind(Graph::vmap::iterator,
              Graph::vmap::iterator,
              QMap<QString,Node*>&);
    Node* find(Node*);
    void merge(Node*,Node*);
    friend class Graph;
};

#endif // UNIONFIND_H
