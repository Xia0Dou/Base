//
// Created by Administrator on 2018/8/22/022.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "ListNode.h"

template <class T>
class List {
private:
    //ListNode<T> * dummyHead;
    ListNode<T> * head;
    ListNode<T> * tail;
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

    ListNode<T> * getNode(int index);   //获取节点
    ListNode<T> * getHead();
    ListNode<T> * getTail();

    void display();                     //显示
};

template <class T>
List<T>::List() {
    head = new ListNode<T>;

    head->setNext(tail);
    tail = head;
    tail->setNext(NULL);
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
List<T>::~List() {
    removeAll();
    delete head;
}

template <class T>
bool List<T>::empty() {
    return  head->getNext() == NULL;
}

template <class T>
void List<T>::insert(int index, T value) {
    if(index>getCount()||index<0)
        return;

    ListNode<T> * inList = new ListNode<T>(value);
    ListNode<T> * ele = head;
    if(head->getNext()==NULL){
        tail = inList;
    }
    while(index){
        ele = ele->getNext();
        --index;
    }
    inList->setNext(ele->getNext());
    ele->setNext(inList);
}

template <class T>
void List<T>::insertHead(T value) {
    ListNode<T> * inList = new ListNode<T>(value);
    if(head->getNext()==NULL){
        tail = inList;
    }
    inList->setNext(head->getNext());
    head->setNext(inList);
}

template <class T>
void List<T>::insertTail(T value) {
    ListNode<T> * inList = new ListNode<T>(value);
    tail->setNext(inList);
    tail = tail->getNext();
    tail->setNext(NULL);
}

template <class T>
void List<T>::remove(int index) {
    if(index>getCount()||index<0)
        return;
    ListNode<T> *reList = head;
    while(index){
        reList = reList->getNext();
        --index;
    }

    ListNode<T> *preList = reList->getNext();
    if(preList==tail)
        tail = reList;
    reList->setNext(preList->getNext());
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
int List<T>::getCount() {
    int count = 0;
    ListNode<T> * ele = head->getNext();
    while(ele!=NULL){
        ele = ele->getNext();
        ++count;
    }
    return count;
}

template <class T>
T List<T>::getData(int index) {
    if(index<0||index>getCount())
        return 0;
    ListNode<T> * ele = head->getNext();
    while(index){
        ele = ele->getNext();
        --index;
    }
    return ele->getData();
}

template <class T>
ListNode<T>* List<T>::getNode(int index) {
    if(index<0||index>getCount())
        return NULL;
    ListNode<T> * ele = head->getNext();
    while(index){
        ele = ele->getNext();
        --index;
    }
    return ele;
}

template <class T>
ListNode<T>* List<T>::getHead() {
    getNode(0);
}

template <class T>
ListNode<T>* List<T>::getTail() {
    getNode(getCount()-1);
}

template <class T>
void List<T>::display() {
    ListNode<T> * ele = head->getNext();
    while(ele!=NULL){
        std::cout<<ele->getData()<<",";
        ele = ele->getNext();
    }
    std::cout<<std::endl;
}

#endif //LIST_LIST_H
