//
// Created by mauri on 19-Apr-20.
//

#ifndef SIMPLE_EXAMPLE_ITERATOR_H
#define SIMPLE_EXAMPLE_ITERATOR_H

#include "Node.h"
template <typename T>
class iterator{
private:
    typedef Node<T> Node;
    Node * node_ptr;
public:
    iterator(){
        node_ptr = nullptr;
    }
    iterator(Node * node_ptr){this-> node_ptr = node_ptr;}
    void operator ++(){
        node_ptr = node_ptr-> next;
    }
    T operator *(){
        return node_ptr-> value;
    }
    bool operator ==(const iterator &it){
        return this-> node_ptr == it.node_ptr;
    }
    bool operator !=(const iterator &it){
        return this-> node_ptr != it.node_ptr;
    }
};


#endif //SIMPLE_EXAMPLE_ITERATOR_H
