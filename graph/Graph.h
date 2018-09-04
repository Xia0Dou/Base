//
// Created by Administrator on 2018/9/4/004.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Graph{
private:
    int v;  //顶点数
    int e;  //边数
    bool dir;   //是否有向
    vector< vector<bool> > g;    //邻接矩阵

public:
    Graph(int v,bool dir):v(v),dir(dir)
    {
        e = 0;
        g = vector< vector<bool> >(v,vector<bool>(v,false));
    }

    ~Graph(){}

    int V(){    //获取顶点数
        return v;
    }

    int E(){    //获取边数
        return e;
    }

    bool haveEdge(int a,int b){ //两点是否有边
        assert(a>=0&&a<v);
        assert(b>=0&&b<v);
        return g[a][b];
    }

    void insertEdge(int a,int b){   //添加边
        assert(a>=0&&a<v);
        assert(b>=0&&b<v);
        if(g[a][b])
            return ;

        g[a][b] = true;
        if(!dir)
            g[b][a] = true;

        ++e;
    }

    void show(){
        for(int i=0;i<v;++i){
            for(int j=0;j<v;++j)
                cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    class graphIterator{        //迭代器来遍历这个图上与v相连的顶点
    private:
        Graph &G;   //图引用
        int v;      //顶点
        int index;

    public:
        graphIterator(Graph &graph,int v):G(graph),v(v){

            index = -1;     //初始化，索引为-1
        }

        ~graphIterator(){}

        int begin(){
            index = -1;
            return next();
        }

        int next(){         //索引向后搜索，找到与它相连的顶点，返回顶点位置，否则返回-1
            for(index+=1;index<G.V();++index){
                if(G.g[v][index])
                    return index;
                return -1;
            }
        }

        int end(){      //查看索引是否验证完毕
            return index>=G.V();
        }
    };

};


#endif //GRAPH_GRAPH_H
