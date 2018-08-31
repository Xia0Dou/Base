#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int> t;
    t.insertHead(1);
    t.insertTail(2);
    t.insert(1,3);
    t.display();

    t.removeHead();
    t.display();

    cout<<t.getData(1)<<endl;
    cout<<t.getCount()<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}