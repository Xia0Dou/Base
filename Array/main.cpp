#include <iostream>
#include <assert.h>
#include "Array.h"

using namespace std;

template <typename T>
void showArray(Array<T> *arr){
    int size = arr->getSize();
    for(int i=0;i<size;++i){
        cout<<arr->findArr(i)<<"\t";
    }
    cout<<endl;
}


int main() {
    Array<int> *arr = new Array<int>(10);

    cout<<"cap:"<<arr->getCap()<<endl;
    cout<<endl;

    for(int i=0;i<arr->getCap();++i)    //添加数组元素
        arr->insertLast(i);
    cout<<"array:"<<endl;
    showArray(arr);
    cout<<endl;

    cout<<"delete of num:"<<arr->deletefirst()<<endl;                 //删除
    cout<<"delete of array:"<<endl;
    showArray(arr);
    cout<<endl;

    cout<<"revise of num:"<<arr->reviseArr(1,10)<<endl;               //替换
    cout<<"revise of array:"<<endl;
    showArray(arr);
    cout<<endl;

    cout<<"find of num:"<<arr->findLast()<<endl;                    //查找
    cout<<endl;

    for(int i=0;i<10;++i)                          //扩容
        arr->insertLast(i);
    cout<<"array:"<<endl;
    showArray(arr);
    cout<<"cap:"<<arr->getCap()<<endl;
    cout<<"size:"<<arr->getSize()<<endl;

    return 0;
}