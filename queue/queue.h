//
// Created by Administrator on 2018/8/31/031.
//  利用链表实现队列
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "list.h"

template <typename T>

class Queue{

private:
    List<T> *que;

public:
    Queue(){
        que = new List<T>();
    }

    ~Queue(){
        delete que;
    }

    void push(T value){
        que->insertTail(value);
    }

    void pop(){
        que->removeHead();
    }

    T front(){
        return que->getData(0);
    }

    T back(){
        return que->getData(que->getCount()-1);
    }

    int size(){
        return que->getCount();
    }

    bool empty(){
        return que->getCount()==0;
    }
};

#endif //QUEUE_QUEUE_H
