#include "disjointset.h"
#include <QMap>
#include <QString>

DisJointSet::DisJointSet(Graph::vmap::iterator begin ,
                     Graph::vmap::iterator end,
                     QMap<QString, Node *> &nodes){
    for(Graph::vmap::iterator it = begin ; it != end ; ++it){
        DisJointSet::Node* nnode = new DisJointSet::Node();
        nodes[it.key()] = nnode;
    }
}
DisJointSet::Node* DisJointSet::find(Node* node){
    if(node != node->parent)
        node->parent = find(node->parent);
    return node->parent;
}
void DisJointSet::merge(Node* x,Node* y){
    x = find(x);
    y = find(y);

    if(x->height > y->height)
        y->parent = x;
    else{
        x->parent = y;
        if(x->height == y->height)
            ++(y->height);
    }
}

