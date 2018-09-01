#include <iostream>
//#include <map>
#include "map.h"

using namespace std;

//template <typename T>
//void display(const T& input){
//    for(auto element=input.cbegin();element!=input.cend();++element)
//        cout<<element->first<<"->"<<element->second<<",";
//    cout<<endl<<endl;
//}

int main() {

    Map<int,int> inmap;              //map<int,string,greater<int>>升序排列


    inmap.insert(8,10);          //insert添加
    inmap.insert(2,20);
    inmap.insert(4,30);

    inmap.show();

    auto ele = inmap.find(2);                  //find查找
    cout<<ele<<endl;

    inmap.erase(2);              //erase删除

    inmap.show();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}