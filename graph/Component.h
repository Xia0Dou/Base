//
// Created by Administrator on 2018/9/4/004.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component{
private:
    Graph &G;   //传递图的引用
    int count;  //记录联通分量个数
    bool *visited;   //记录是否访问
    int *num;       //记录顶点的联通区域

    void dfs(int v){        //深度优先遍历
        visited[v] = true;      //将遍历到的顶点记为true
        num[v] = count;         //记录该顶点的联通区域
        typename Graph::graphIterator gra(G,v);     //使用迭代器遍历所有顶点
        for(auto i=gra.begin();!gra.end();i=gra.next()){
            if(!visited[i])     //如果未遍历
                dfs(i);
        }
    }

public:
    Component(Graph &graph):G(graph){
        count = 0;
        visited = new bool[G.V()];
        num = new int[G.V()];

        for(int i=0;i<G.V();++i){
            visited[i] = false;
            num[i] = -1;
        }

        for(int i=0;i<G.V();++i) {  //获取联通分量
            if(!visited[i]){
                dfs(i);
                ++count;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] num;
    }

    int Count(){        //返回联通分量个数
        return count;
    }

    int Num(int a,int b){   //检查两顶点是否相连
        assert(a>=0&&a<G.V());
        assert(b>=0&&b<G.V());
        return num[a] == num[b];
    }

};


#endif //GRAPH_COMPONENT_H
