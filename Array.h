//
// Created by Administrator on 2018/8/19/019.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H



template < typename T >
class Array{
private:
    T *array;                       //数组
    int size;                       //数组大小
    int cap;                        //数组容量
    void new_cap(int newcap) {      //动态更改数组容量
        cap = newcap;
        T *newArray = new T[cap];
        for(int i=0;i<size;++i)
            newArray[i] = array[i];
        array = newArray;
        delete[] newArray;
    }
public:
    //构造函数，默认大小为10
    Array() {
        cap = 10;
        array = new T[cap];
        size = 0;
    }

//构造函数
    Array(int incap) {
        cap = incap;
        array = new T[cap];
        size = 0;
    }

//析构函数
    ~Array() {
        delete[] array;
        cap = 0;
        size = 0;
    }

//获得容量大小
    int getCap(){
        return cap;
    }

//获得数组大小
    int getSize() {
        return size;
    }

//添加数组元素
    void insertArr(int index, T value) {
        assert(size>=0&&size>=index);
        if(size>=cap)
            new_cap(cap+1);
        for(int i = size ; i > index-1 ; --i)
            array[i] = array[i-1];
        array[index] = value;
        ++size;
    }

//在最前添加
    void insertfirst(T value){
        insertArr(0,value);
    }

//在最后添加
    void insertLast(T value){
        insertArr(size,value);
    }

//删除指定位置数组元素
    T deleteArr(int index) {
        assert(index>=0&&index<size);
        T outVal = array[index];
        for(int i=index;i<size;++i)
            array[i] = array[i+1];
        --size;
        if(size<(cap/3)&&cap/2!=0)
            new_cap(cap/2);
        return outVal;
    }

    T deletefirst(){
        deleteArr(0);
    }

    T deleteLast(){
        deleteArr(size-1);
    }

//删除指定元素
    void deleteVal(T value) {
        int temp = 0;
        for(int i=0;i<size;++i){
            if(array[i]!=value)
                array[temp++] = array[i];
        }
        if(size<(cap/3))
            new_cap(cap/2);
    }

//修改指定位置元素，返回原来的元素
    T reviseArr(int index, T value) {
        assert(index>=0&&index<size);
        T outVal = array[index];
        array[index] = value;
        return outVal;
    }

//修改指定元素
    void reviseVal(T value, T val) {
        for(int i=0;i<size;++i){
            if(array[i]==value)
                array[i] = val;
        }
    }

//查找指定位置的元素
    T findArr(int index) {
        assert(index>=0&&index<size);
        return array[index];
    }

    T findFirst(){
        findArr(0);
    }

    T findLast(){
        findArr(size-1);
    }
//查找元素，返回第一次出现的位置
    int findVal(T value) {
        for(int i=0;i<size;++i){
            if(array[i]==value)
                return i;
        }
    }


};


#endif //ARRAY_ARRAY_H
