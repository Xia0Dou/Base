#include <iostream>
#include "queue.h"

using namespace std;

int main() {

    Queue<int> inque;

    inque.push(1);
    inque.push(2);
    inque.push(3);
    inque.push(4);

    cout<<"front:"<<inque.front()<<endl;
    cout<<"back:"<<inque.back()<<endl<<endl;

    inque.pop();

    cout<<"front:"<<inque.front()<<endl;

    cout<<"size:"<<inque.size()<<endl;

    if(!inque.empty())
        cout<<"no empty"<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}