//
// Created by mauri on 09-Apr-20.
//
#ifndef SIMPLE_EXAMPLE_NODE_H
#define SIMPLE_EXAMPLE_NODE_H
template <typename T>
class Node {
    public:
        T value;
        Node<T> * next;
        Node(){
            next = nullptr;
        }

        ~Node(){
        }
};
template <typename T>
class doublyNode:public Node<T>{
public:
    doublyNode<T> * back;
    doublyNode<T> * next;
    doublyNode(){
        Node<T>();
        back = nullptr;
    }

    ~doublyNode(){
    }
};

#endif //SIMPLE_EXAMPLE_NODE_H