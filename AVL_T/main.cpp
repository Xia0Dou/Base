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

    while(!tree.isAVL()){       //转化为AVL树
        tree.avl();
    }


    tree.levelOrder();

    cout<<tree.isAVL()<<endl;



    tree.remove(7);

    tree.levelOrder();

    cout<<tree.isAVL()<<endl;

    while(!tree.isAVL()){
        tree.avl();
    }

    tree.levelOrder();

    cout<<tree.isAVL()<<endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}