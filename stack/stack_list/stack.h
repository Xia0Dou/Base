//
// Created by Administrator on 2018/8/31/031.
//  利用链表作为底层结构，实现栈
//

#ifndef STACK_LIST_STACK_H
#define STACK_LIST_STACK_H

#include "list.h"

template<typename T>
class Stack{

private:
    List<int> *sta;

public:
    Stack(){
        sta = new List<T>();     //利用Array构造栈
    }
    ~Stack(){
        delete sta;
    }

    void push(T value){            //入栈
        sta->insertTail(value);
    }


    void pop(){                     //出栈
        sta->removeTail();
    }

    T top(){                        //取栈顶元素
        return sta->getData(size()-1);
    }

    int size(){                     //栈大小
        return sta->getCount();
    }

    bool empty(){                   //判断栈是否为空
        return sta->getCount()==0;
    }

    void display(){                 //打印
        sta->display();
    }
};

#endif //STACK_LIST_STACK_H
