//
// Created by Administrator on 2018/9/1/001.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H

#include "BST.h"

template <typename T,typename P>

class Map{

private:
    Tree<T,P> * map;

public:
    Map(){
        map = new Tree<T,P>();

    }

    ~Map(){
        delete map;
    }

    int size(){
        return map->size();
    }

    bool empty(){
        return size()==0;
    }

    void insert(T value,P price){
        map->insert(value,price);
    }

    void erase(T value){
        map->remove(value);
    }

    P find(T value){
        return map->find(value);
    }

    void show(){
        map->inOrder();
    }

    P getmin(){
        return map->getmin();
    }

    P getmax(){
        return map->getmax();
    }



};

#endif //MAP_MAP_H
