//
// Created by mauri on 14-Apr-20.
//

#pragma once
template <typename T>
struct Node {
    T value;
    Node *  next;
};

template <typename T>
struct doublyNode{
    T value;
    doublyNode<T> * next;
    doublyNode<T> * back;
};
