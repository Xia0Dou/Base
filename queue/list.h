//
// Created by Administrator on 2018/8/31/031.
//
//  链表实现

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stddef.h>
//#include "ListNode.h"

template <typename T>
class List {
private:

    //template <typename T>
    class ListNode{         //节点类
    public:
        T data;                          //节点数据
        ListNode *next;                  //节点指针

        ListNode(){next=NULL;}          //默认构造函数
        ListNode(T value){next=NULL;data=value;}        //构造函数，设置值
        ~ListNode(){}                                    //析构函数

    };
    //ListNode<T> * dummyHead;
    ListNode * head;
    ListNode * tail;
public:
    List();                      //构造函数
    //List(T value);
    ~List();                    //析构函数

    bool empty();                  //判断链表是否为空

    void insert(int index, T value);        //添加节点
    void insertHead(T value);               //链表前添加节点
    void insertTail(T value);               //链表后添加节点

    void remove(int index);             //删除节点
    void removeHead();
    void removeTail();
    void removeAll();

    int getCount();                     //获取链表长度
    T getData(int index);               //获取节点值

    ListNode * getNode(int index)   //获取节点
    {
        if(index<0||index>getCount())
            return NULL;
        ListNode * ele = head->next;
        while(index){
            ele = ele->next;
            --index;
        }
        return ele;
    }
    ListNode * getHead(){
        getNode(0);
    }
    ListNode * getTail(){
        getNode(getCount()-1);
    }

    void display();                     //显示
};

template <class T>
List<T>::List() {                   //构造函数
    head = new ListNode();

    head->next = tail;
    tail = head;
    tail->next = NULL;
}

//template <class T>
//List<T>::List(T value) {
//    dummyHead = new ListNode<T>;
//    //head = new ListNode<T>(value);
//    dummyHead->setNext(head);
//    //tail = head;
//    tail->setNext(NULL);
//}

template <class T>
List<T>::~List() {              //析构函数
    removeAll();
    delete head;
}

template <class T>
bool List<T>::empty() {         //判断链表是否为空
    return  head->next == NULL;
}

template <class T>
void List<T>::insert(int index, T value) {      //添加节点
    if(index>getCount()||index<0)
        return;

    ListNode * inList = new ListNode(value);
    ListNode * ele = head;
    if(head->next==NULL){
        tail = inList;
    }
    while(index){
        ele = ele->next;
        --index;
    }
    inList->next = ele->next;
    ele->next = inList;
}

template <class T>
void List<T>::insertHead(T value) {
    ListNode * inList = new ListNode(value);
    if(head->next==NULL){
        tail = inList;
    }
    inList->next = head->next;
    head->next = inList;
}

template <class T>
void List<T>::insertTail(T value) {
    ListNode * inList = new ListNode(value);
    tail->next = inList;
    tail = tail->next;
    tail->next = NULL;
}

template <class T>
void List<T>::remove(int index) {       //删除节点
    if(index>getCount()||index<0)
        return;
    ListNode *reList = head;
    while(index){
        reList = reList->next;
        --index;
    }

    ListNode *preList = reList->next;
    if(preList==tail)
        tail = reList;
    reList->next = preList->next;
    delete preList;
}

template <class T>
void List<T>::removeHead() {
    remove(0);
}

template <class T>
void List<T>::removeTail() {
    remove(getCount()-1);
}

template <class T>
void List<T>::removeAll() {
    for(int i=getCount()-1;i>=0;--i)
        removeTail();
}

template <class T>
int List<T>::getCount() {           //获取节点数
    int count = 0;
    ListNode * ele = head->next;
    while(ele!=NULL){
        ele = ele->next;
        ++count;
    }
    return count;
}

template <class T>
T List<T>::getData(int index) {    //获取节点值
    if(index<0||index>getCount())
        return 0;
    ListNode * ele = head->next;
    while(index){
        ele = ele->next;
        --index;
    }
    return ele->data;
}


template <class T>
void List<T>::display() {       //打印
    ListNode * ele = head->next;
    while(ele!=NULL){
        std::cout<<ele->data<<",";
        ele = ele->next;
    }
    std::cout<<std::endl;
}

#endif //LIST_LIST_H


