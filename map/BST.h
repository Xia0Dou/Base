//
// Created by Administrator on 2018/9/1/001.
//
//  二叉搜索树
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>
#include <stack>
#include <queue>


template <typename T,typename P>
//template <typename P>

class Tree{                 //二叉树类

public:

    class Node{             //节点类
    public:
        T val;
        P pri;
        Node * left;
        Node * right;
        Node(T e,P price):val(e),pri(price),left(NULL),right(NULL){}
        Node(Node *node):val(node->val),pri(node->pri),left(node->left),right(node->right){}
    };

private:
    Node * root;            //定义节点

public:
    Tree():root(NULL){}      //构造函数
    ~Tree(){                    //析构函数
        del(root);
    }

private:
    void del(Node * node){
        if(node==NULL)
            return ;
        else{
            del(node->left);
            del(node->right);
            delete node;
        }
    }

    int count;

public:
    int size(){           //获取节点数
        count = 0;
        size(root);
        return count;
    }

private:

    void size(Node * node){
        if(node==NULL)
            return;

        size(node->left);
        size(node->right);
        ++count;

    }

public:
    bool empty(){                   //判断二叉树是否为空
        return size()==0;
    }

    void insert(T value,P price){           //添加元素
        root = insert(root,value,price);
    }

private:
    Node * insert(Node * node,T value,P price){
        if(node==NULL){                     //节点为空，则添加到该位置
            Node * newNode = new Node(value,price);
            return newNode;
        }
        else if(value<node->val){           //小于该节点的值，则在左孩子找
            node->left = insert(node->left,value,price);
        }
        else if(value>node->val){           //大于该节点的值，则在右孩子找
            node->right = insert(node->right,value,price);
        }
    }

public:
    void remove(T value){              //删除节点
        root = remove(root,value);
    }

private:
    Node * remove(Node * node,T value){
        if(node==NULL)
            return node;
        if(value==node->val){                //删除节点左右子树均为空，直接删除
//            if(node->left==NULL&&node->right==NULL){
//                delete node;
//            }

            if(node->left==NULL){      //删除节点左子树为空
                node = node->right;
                //delete node;
            }

            else if(node->right==NULL){     //删除节点右子树为空
                node = node->left;
                //delete node;
                //return newNode;
            }

                //删除节点左右子树均不为空，找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
                // 用这个节点顶替待删除节点的位置
            else{
                Node* newNode = node->right;
                while(newNode->left)
                    newNode = newNode->left;
                node->val = newNode->val;
                node->right = remove(node->right,newNode->val);

//                delete getmin(node->right);
//                newNode->right = node->right;
//                newNode->left = node->left;
//                delete node;
//                return  newNode;
            }
        }
        else if(value<node->val)
            node->left = remove(node->left,value);
        else
            node->right = remove(node->right,value);

        return node;
    }

public:
    P find(T value){           //查找二叉树中是否存在value
        return find(root,value);
    }

private:
    P find(Node * node,T value){
        if(node==NULL)
            return 0;
        if(value==node->val)
            return node->pri;
        else if(value<node->val)
            return find(node->left,value);
        else
            return find(node->right,value);
    }


    //树的遍历

    //深度优先遍历
public:
    int preOrder(){        //前序遍历

        std::cout<<"preOrder:"<<std::endl;

        preOrder(root);
        std::cout<<std::endl;


        preOrderN(root);
        std::cout<<std::endl;

    }

private:
    void preOrder(Node * node){     //递归算法
        if(node==NULL)
            return ;

        std::cout<<node->val<<"->"<<node->pri<<" ";

        preOrder(node->left);

        preOrder(node->right);

    }

    void preOrderN(Node * node){        //非递归算法，利用栈实现
        if(node==NULL)
            return ;
        std::stack<Node *> sta;

        while(node||!sta.empty()){
            while(node){
                sta.push(node);

                std::cout<<node->val<<"->"<<node->pri<<" ";

                node = node->left;
            }
            node = sta.top();
            sta.pop();
            node = node->right;
        }
    }

public:
    void inOrder(){        //中序遍历

        //std::cout<<"inOrder:"<<std::endl;

        //inOrder(root);
        //std::cout<<std::endl;

        inOrderN(root);
        std::cout<<std::endl;
    }

private:
    void inOrder(Node * node){     //递归算法
        if(node==NULL)
            return ;

        inOrder(node->left);

        std::cout<<node->val<<"->"<<node->pri<<" ";

        inOrder(node->right);

    }

    void inOrderN(Node * node){        //非递归算法，利用栈实现
        if(node==NULL)
            return ;
        std::stack<Node *> sta;

        while(node||!sta.empty()){
            while(node){
                sta.push(node);

                node = node->left;
            }
            node = sta.top();

            std::cout<<node->val<<"->"<<node->pri<<" ";

            sta.pop();
            node = node->right;
        }
    }

public:
    void postOrder(){        //后序遍历

        std::cout<<"postOrder:"<<std::endl;

        postOrder(root);
        std::cout<<std::endl;

        postOrderN(root);
        std::cout<<std::endl;

    }

private:
    void postOrder(Node * node){     //递归算法
        if(node==NULL)
            return ;

        postOrder(node->left);

        postOrder(node->right);

        std::cout<<node->val<<"->"<<node->pri<<" ";

    }

    void postOrderN(Node * node){   //非递归算法，使用两个栈实现
        if(node==NULL)
            return ;

        std::stack<Node *> sta;
        std::stack<Node *> ack;

        sta.push(node);

        while(!sta.empty()){
            node = sta.top();
            sta.pop();

            ack.push(node);

            if(node->left)
                sta.push(node->left);
            if(node->right)
                sta.push(node->right);
        }

        while(!ack.empty()){
            node = ack.top;

            std::cout<<node->val<<"->"<<node->pri<<" ";

            ack.pop();
        }
    }


    //广度优先遍历
    //层序遍历
public:
    void levelOrder(){

        std::cout<<"levelOrder:"<<std::endl;
        levelOrder(root);
        std::cout<<std::endl;
    }

private:
    void levelOrder(Node * node){
        if(node==NULL)
            return ;

        std::queue<Node *> que;     //使用队列实现

        que.push(node);

        while(!que.empty()){

            node = que.front();

            std::cout<<node->val<<"->"<<node->pri<<" ";

            que.pop();

            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);

        }
    }

public:
    P getmin(){             //获取键值最小值对应的值
        if(size()==0)
            throw "BST is NULL";

        return getmin(root)->pri;
    }

private:
    Node * getmin(Node * node){
        if(node->left==NULL)
            return node;
        else
            return getmin(node->left);
    }


public:
    P getmax(){             //获取键值最大值对应的值
        if(size()==0)
            throw "BST is NULL";

        return getmax(root)->pri;
    }

private:
    Node * getmax(Node * node){
        if(node->right==NULL)
            return node;
        else
            return getmax(node->right);
    }


};


#endif //BST_BST_H

