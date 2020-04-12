//
// Created by mauri on 09-Apr-20.

#include "List.cpp"
#include "doublyList.cpp"
int main(){
    linkedLists::LinkedList<int>list;
    linkedLists::doublyLinkedList<int>  list2;
    list2.push_back(10);
    list2.push_back(10);
    list2.push_back(20);
    list2.push_back(10);
    list2.push_back(30);
    list2.push_back(30);
    list2.push_back(10);
    list2.push_back(30);
    list2.push_back(20);
    list2.remove(20);
    //list.pop_front();
    //std::cout<<list2.pop_back()<<std::endl;
    //std::cout<<list2.back()<<std::endl;
     for (int i = 0; i<list2.size();i++)
        std::cout<<list2[i]<<std::endl;
    //std::cout<<list.front()<<std::endl;

}