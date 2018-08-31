#include <iostream>
#include "stack.h"

using namespace std;




int main() {
    Stack<int> a ;
    a.push(1);
    a.push(2);
    a.push(3);

    a.display();
    cout<<a.size()<<endl;
    cout<<a.top()<<endl;
    cout<<a.empty()<<endl;
    a.pop();
    a.display();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}