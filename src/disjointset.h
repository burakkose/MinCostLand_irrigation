#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include "graph.h"

class DisJointSet
{
private:
    class Node{
    public:
        int height;
        Node* parent;
        Node():height(0),parent(this){}
    };
public:
    DisJointSet(Graph::vmap::iterator,
              Graph::vmap::iterator,
              QMap<QString,Node*>&);
    Node* find(Node*);
    void merge(Node*,Node*);
    friend class Graph;
};

#endif // DISJOINTSET_H
