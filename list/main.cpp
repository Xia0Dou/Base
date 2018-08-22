#include <iostream>
//#include "ListNode.h"
#include "List.h"
//#include <list>

using namespace std;

int main() {

    List<int> firstList;

    cout<<firstList.getCount()<<endl;

    firstList.insertHead(6);
    firstList.display();

    firstList.insertTail(2);
    firstList.insert(0,7);
    firstList.insertTail(3);
    firstList.insertTail(4);
    firstList.insertHead(8);

    firstList.display();

    firstList.removeTail();
    firstList.remove(0);

    cout<<firstList.getData(0)<<endl;

    cout<<firstList.getCount()<<endl;
    firstList.display();
    return 0;
}