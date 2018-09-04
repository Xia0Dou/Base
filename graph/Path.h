//
// Created by Administrator on 2018/9/4/004.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

template <typename Graph>
class Path{     //路径查找
private:
    Graph &G;   //图引用
    int v;      //起始顶点
    bool *visited;  //记录顶点是否遍历
    int *from;      //记录顶点的上一个顶点

    void dfs(int v){        //深度优先遍历
        visited[v] = true;      //将遍历到的顶点记为true
        //num[v] = count;         //记录该顶点的联通区域
        typename Graph::graphIterator gra(G,v);     //使用迭代器遍历所有顶点

        for(auto i=gra.begin();!gra.end();i=gra.next()){

            if(!visited[i]) {    //如果未遍历
                from[i] = v;    //记录上个顶点
                dfs(i);
            }

        }
    }

public:
    Path(Graph &graph,int v):G(graph),v(v){
        visited = new bool[G.V()];
        from = new int[G.V()];

        for(int i=0;i<G.V();++i){
            visited[i] = false;
            from[i] = -1;
        }

        dfs(v);     //寻路
    }

    ~Path(){
        delete[] visited;
        delete[] from;
    }

    bool havePath(int x){       //检查是否存在v-x的路径
        assert(x>=0&&x<G.V());
        return visited[x];
    }

    void path(int x,vector<int> &vec){  //记录v-x的路径
        assert(x>=0&&x<G.V());
        if(!havePath(x))
            return ;

        stack<int> sta;        //from逆向查找路径，存于栈

        while(from[x]!=-1){
            sta.push(from[x]);
            x = from[x];
        }

        while(!sta.empty()){
            vec.push_back(sta.top());
            sta.pop();
        }
    }

    void showPath(int x){       //打印路径
        if(!havePath(x))
            return ;
        vector<int> vec;
        path(x,vec);
        for(int i=0;i<vec.size()-1;++i)
            cout<<vec[i]<<"->";
        cout<<vec[vec.size()-1]<<endl;
    }

};


#endif //GRAPH_PATH_H
