//
// Created by Administrator on 2018/8/31/031.
//  动态数组作为底层实现栈
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "Array.h"

template<typename T>
class Stack{
private:
    Array<T> *sta;

public:
    Stack(){
        sta = new Array<T>();     //利用Array构造栈
    }
    ~Stack(){
        delete sta;
    }

    void push(T value){            //入栈
        sta->insertLast(value);
    }


    void pop(){                     //出栈
        sta->deleteLast();
    }

    T top(){                        //取栈顶元素
        return sta->findLast();
    }

    int size(){                     //栈大小
        return sta->getSize();
    }

    bool empty(){                   //判断栈是否为空
        return sta->getSize()==0;
    }

    void display(){                 //打印
        sta->display();
    }
};

#endif //STACK_STACK_H
