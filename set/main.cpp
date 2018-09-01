#include <iostream>
//#include <set>
#include "set.h"

using namespace std;

//template <typename T>
//void display(const T& input){
//    for(auto element=input.begin();element!=input.end();++element)
//        cout<<*element<<",";
//    cout<<endl;
//}

int main() {

    Set<int> inset;

    inset.insert(2);              //insert添加
    inset.insert(1);
    inset.insert(4);
    inset.insert(3);

    cout<<inset.count(0)<<endl;

    inset.show();


    cout<<inset.find(4)<<endl;      //find查找


    inset.erase(2);            //erase删除

    inset.show();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}