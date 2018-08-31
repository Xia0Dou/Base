#include <iostream>
#include "bst.h"

using namespace std;

int main() {

    Tree<int> * tree ;

    int arr[] = {5,2,8,6,1};

    for(int i=0;i<5;++i)
        tree->insert(arr[i]);

    tree->preOrder();
    tree->inOrder();
    tree->postOrder();

    tree->levelOrder();

    //tree->remove(5);

    cout<<"max:"<<tree->getmax()<<endl;

    cout<<"min:"<<tree->getmin()<<endl;

    cout<<"size:"<<tree->size()<<endl;

    cout<<"empty:"<<tree->empty()<<endl;

    return 0;
}