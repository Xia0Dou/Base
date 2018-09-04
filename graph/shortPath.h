//
// Created by Administrator on 2018/9/4/004.
//

#ifndef GRAPH_SHORTPATH_H
#define GRAPH_SHORTPATH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

template <typename Graph>
class shortPath{
private:
    Graph &G;   //图引用
    int v;      //起始顶点
    bool *visited;  //记录顶点是否遍历
    int *from;      //记录顶点的上一个顶点
    int *way;       //记录图中顶点的次序

public:
    shortPath(Graph &graph,int v):G(graph),v(v){
        visited = new bool[G.V()];
        from = new int[G.V()];
        way = new int[G.V()];

        for(int i=0;i<G.V();++i){
            visited[i] = false;
            from[i] = -1;
            way[i] = -1;
        }

        //无向图最短路径，广度优先遍历
        queue<int> que;
        que.push(v);

        visited[v] = true;
        way[v] = 0;

        while(!que.empty()){
            int top = que.front();
            que.pop();

            typename Graph::graphIterator gra(G,top);
            for(int i=gra.begin();!gra.end();i=gra.next()){
                if(!visited[i]){
                    visited[i] = true;
                    way[i] = way[top] + 1;
                    from[i] = top;
                    que.push(i);
                }
            }
        }
    }

    ~shortPath(){
        delete[] visited;
        delete[] from;
        delete[] way;
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
        assert(x>=0&&x<G.V());
        if(!havePath(x))
            return ;
        vector<int> vec;
        path(x,vec);
        for(int i=0;i<vec.size()-1;++i)
            cout<<vec[i]<<"->";
        cout<<vec[vec.size()-1]<<endl;
    }

    int ways(int x){        //最短路径长度
        assert(x>=0&&x<G.V());
        return way[x];
    }

};

#endif //GRAPH_SHORTPATH_H
