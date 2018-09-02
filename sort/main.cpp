#include <iostream>

#include "sort.h"

using namespace std;



int main() {


    vector<int> vec = myRand();

    display(vec);

    vector<int> arr = myRand();

    insertSort(arr);
    cout<<"insertSort:       ";
    display(arr);


    vector<int> arr1 = myRand();

    binaryInsertSort(arr1);
    cout<<"binaryInsertSort: ";
    display(arr1);


    vector<int> arr2 = myRand();

    selectSort(arr2);
    cout<<"selectSort:       ";
    display(arr2);


    vector<int> arr3 = myRand();

    quickSort(arr3);
    cout<<"quickSort:        ";
    display(arr3);

    vector<int> arr4 = myRand();

    mergeSort(arr4);
    cout<<"mergeSort:        ";
    display(arr4);

    vector<int> arr5 = myRand();

    heapSort(arr5);
    cout<<"heapSort:         ";
    display(arr5);


    return 0;
}