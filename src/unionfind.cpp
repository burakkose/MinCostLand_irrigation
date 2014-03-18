#include "unionfind.h"
#include <QMap>
#include <QString>

UnionFind::UnionFind(Graph::vmap::iterator begin ,
                     Graph::vmap::iterator end,
                     QMap<QString, Node *> &nodes){
    for(Graph::vmap::iterator it = begin ; it != end ; ++it){
        UnionFind::Node* nnode = new UnionFind::Node();
        nodes[it.key()] = nnode;
    }
}
UnionFind::Node* UnionFind::find(Node* node){
    if(node != node->parent)
        node->parent = find(node->parent);
    return node->parent;
}
void UnionFind::merge(Node* x,Node* y){
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

