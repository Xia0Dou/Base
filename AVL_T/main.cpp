#include <iostream>
#include "avltree.h"

using namespace std;


int main() {
    Tree<int> tree;

    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(1);
    tree.insert(0);
    tree.insert(-1);
    tree.insert(-2);

    //cout<<tree.size()<<endl;

    //cout<<tree.tf()<<endl;

    tree.levelOrder();          //层序遍历

    cout<<tree.isAVL()<<endl;   //显示是否为AVL树


    tree.remove(7);

    tree.levelOrder();

    cout<<tree.isAVL()<<endl;

    
    return 0;
}
