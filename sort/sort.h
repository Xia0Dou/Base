//
// Created by Administrator on 2018/9/2/002.
//

#ifndef NEWSORT_SORT_H
#define NEWSORT_SORT_H


#include <iostream>
#include <vector>
#include <ctime>
#include<stdlib.h>


using namespace std;


/******************************直接插入排序********************************/
template <typename T>

void insertSort(vector<T> &vec){

    for(int i=0;i<vec.size();++i){       //遍历整个数组

        int temp = vec.at(i);            //记录当前值
        int j = i;

        while(j>0&&vec.at(j-1)>temp){    //与前面的值比较，使i前的数有序
            vec.at(j) = vec.at(j-1);
            --j;
        }

        vec.at(j) = temp;
    }
}

/******************************二分插入排序********************************/
template <typename T>

void binaryInsertSort(vector<T> &vec){

    for(int i=0;i<vec.size();++i){          //遍历

        int left = 0;                //left，right取得前面有序部分
        int right = i-1;

        int temp = vec.at(i);        //插入元素temp

        while(left<=right) {

            int mid = (left+right)>>1;   //取中间值

            if (temp>vec.at(mid))       //若插入值大于中间值，取右半部
                left = mid + 1;

            else
                right = mid - 1;        //若插入值小于中间值，取左半部
        }

        int j ;
        for(j=i;j>left;--j)             //找到插入位置left，将left之后位置后移
            vec.at(j) = vec.at(j-1);

        vec.at(j) = temp;               //将temp插入到left位置
    }

}

/******************************直接选择排序********************************/
template <typename T>

void selectSort(vector<T> &vec){

    for(int i=0;i<vec.size()-1;++i){    //遍历

        int min = i;                    //记录当前索引

        for(int j=i+1;j<vec.size();++j){
            if(vec.at(j)<vec.at(min))       //如果其后有小于索引指向的值，更换索引
                min = j;
        }

        swap(vec.at(i),vec.at(min));        //交换当前值和索引位置值
    }
}

/******************************快速排序********************************/

template <typename T>

void quickSort(vector<T> &vec,int left,int right);

template <typename T>

void quickSort(vector<T> &vec){
    quickSort(vec,0,vec.size()-1);
}


template <typename T>

void quickSort(vector<T> &vec,int left,int right){

    int i = left ;              //记录边界索引
    int j = right ;

    T temp = vec.at(left);         //选择比较元素

    while(i<j){
                                    //第一轮
        if(i<j&&vec.at(j)>=temp)    //如果最后元素大于比较元素，则j向前移动
            --j;                    //否则将它赋值给作为比较的首元素
        vec.at(i) = vec.at(j);

        if(i<j&&vec.at(i)<=temp)    //如果最前元素小于比较元素，则i向后移动
            ++i;                    //否则将它赋值给j位置的元素
        vec.at(j) = vec.at(i);

    }

    vec.at(i) = temp;               //将比较元素赋值给i，j相撞的位置
                                    //此时temp的左边小于等于它，右边大于等于它

    if(i!=left)  quickSort(vec,left,i-1);   //使用递归给i的左右排序
    if(j!=right) quickSort(vec,i+1,right);  //直至i=left,j=right
}

/******************************归并排序********************************/
template <typename T>
void msort(vector<T> &vec,vector<T> &num,int left,int right);       //递归实现分治

template <typename T>
void merge(vector<T> &vec,vector<T> &num,int left,int mid,int right);  //实现数组对接



template <typename T>

void mergeSort(vector<T> &vec){
    vector<T> num(vec);             //新建一个数组，用来临时存储数据
    msort(vec,num,0,vec.size()-1);  //分治
}

template <typename T>
void msort(vector<T> &vec,vector<T> &num,int left,int right){

    if(left<right){

        int mid = (left+right)>>1;      //取中间位置划分开

        msort(vec,num,left,mid);        //左
        msort(vec,num,mid+1,right);     //右

        merge(vec,num,left,mid,right);  //将划分的各组数据排序对接
    }


}

template <typename T>

void merge(vector<T> &vec,vector<T> &num,int left,int mid,int right){

    int i = left;       //左数组的头指针
    int j = mid+1;      //右数组的头指针
    int k = 0;          //中间存储数组的指针

    while(i<=mid&&j<=right){        //保证两个数组都有数据

        if(vec.at(i)<=vec.at(j))
            num.at(k++) = vec.at(i++);

        else if(vec.at(i)>vec.at(j))
            num.at(k++) = vec.at(j++);
    }

    while(i<=mid)                   //如果左数组或右数组还有数据
        num.at(k++) = vec.at(i++);  //就放在num数组最后

    while(j<=right)
        num.at(k++) = vec.at(j++);

    k = 0;

    while(left<=right)              //将num数组数据复制到原数组
        vec.at(left++) = num.at(k++);
}


/******************************堆排序********************************/

template <typename T>

void heap(vector<T> &vec,int i,int len){    //调整大顶堆

    int temp = vec.at(i);                   //获取当前元素

    for(int k=2*i+1;k<len;k=2*k+1){         //从节点i的左孩子开始

        if(k+1<len&&vec.at(k)<vec.at(k+1))  //如果左节点小于右节点
            ++k;                            //k指向右节点
                                            //即k指向大的节点

        if(vec.at(k)>temp){                 //如果子节点大于父节点
            vec.at(i) = vec.at(k);          //赋值给父节点
            i = k;                          //更新i
        }

        else
            break;

    }

    vec.at(i) = temp;
}

template <typename T>

void heapSort(vector<T> &vec){

    for(int i=vec.size()/2-1;i>=0;--i)      //构建大顶堆

        heap(vec,i,vec.size());

    for(int i=vec.size()-1;i>0;--i){        //调整堆

        swap(vec.at(0),vec.at(i));      //交换堆顶和末尾元素

        heap(vec,0,i);                  //重新调整堆
    }

}









template <typename T>

void display(vector<T> vecval){
    for(int i=0;i<vecval.size();++i)
        cout<<vecval.at(i)<<" ";
    cout<<endl;
}



vector<int> myRand(){
    vector<int> vec;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i)
        vec.push_back(rand()%100);
    return vec;
}



vector<int> myRand(int n,int left,int right){
    vector<int> vec;
    srand((unsigned)time(NULL));
    for(int i=0;i<n;++i)
        vec.push_back(left+rand()%(right-left));
    return vec;
}





#endif //NEWSORT_SORT_H
