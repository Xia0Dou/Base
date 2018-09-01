//
// Created by Administrator on 2018/9/1/001.
//  利用BST作为底层实现set
//

#ifndef SET_SET_H
#define SET_SET_H

#include "BST.h"

template <typename T>

class Set{
private:
    Tree<T> * set;

public:

    Set(){                      //构造函数
        set = new Tree<T>();
    }

    ~Set(){                     //析构函数
        delete set;
    }

    bool empty(){               //判断set是否为空
        return set->empty();
    }

    int size(){                 //获得set大小
        return set->size();
    }

    void insert(T value){       //添加元素
        set->insert(value);
    }

    void erase(T value){        //删除元素
        set->remove(value);
    }

    bool find(T value){         //查找
        return set->find(value);
    }

    void show(){                //打印全部元素
        set->inOrder();
    }

    int count(T value){         //查找value出现的次数
        return set->preOrder(value);   //通过对先序遍历的修改，使其返回value出现频率
    }
};

#endif //SET_SET_H
