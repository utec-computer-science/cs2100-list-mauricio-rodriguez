//
// Created by mauri on 09-Apr-20.

#include "Lists/List.cpp"
#include "Lists/doublyList.cpp"
#include "Lists/circledList.cpp"
#include "Lists/doublyCircledList.cpp"
int main(){
    std::cout << "Welcome to docker!!\n";
    using namespace cs2100_doublyCircled;
    linkedList<int> list;
    list.push_back(10);
    list.push_back(7);
    list.push_front(15);
    list.push_front(15);
    list.push_back(14);
    list.push_front(15);
    list.push_back(17);
    list.push_front(10);
    list.push_back(16);
    list.push_back(15);
    list.push_front(13);
    list.push_back(11);
    list.remove(10);
    list.pop_front();
    list.pop_back();
    std::cout<<list.back()<<std::endl;
    list.sort();
    std::cout<<list.size()<<std::endl;
    std::cout<<list<<std::endl;
    //for (auto it = list.begin();it != list.end();++it)
      //  std::cout<<*it<<",";
}