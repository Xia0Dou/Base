//
// Created by Administrator on 2018/8/22/022.
//

#ifndef LIST_LISTNODE_H
#define LIST_LISTNODE_H

#include <stddef.h>

template <class T>
class ListNode{
private:
    T data;                          //节点数据
    ListNode *next;                  //节点指针
public:
    ListNode(){next=NULL;}          //默认构造函数
    ListNode(T value){next=NULL;data=value;}        //构造函数，设置值
    ~ListNode(){}                                    //析构函数
    void setNext(ListNode<T> * inNext);             //节点指针赋值
    void setData(T value);                          //节点数据赋值
    ListNode<T> * getNext();                        //获取节点指针
    T getData();                                    //获取节点数据
};

template <class T>
void ListNode<T>::setNext(ListNode<T> *inNext) {
    next = inNext;
}

template <class T>
void ListNode<T>::setData(T value) {
    data = value;
}

template <class T>
ListNode<T>* ListNode<T>::getNext() {
    return next;
}

template <class T>
T ListNode<T>::getData() {
    return data;
}

#endif //LIST_LISTNODE_H
