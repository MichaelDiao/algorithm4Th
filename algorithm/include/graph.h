/*************************************************************************
  > File Name   : graph.h
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月07日 星期四 15时08分40秒
 ************************************************************************/

#ifndef _GRAPH_H
#define _GRAPH_H

#include <fstream>
#include <iostream>

typedef char VertexType;//顶点类型应由用户定义
typedef int EdgeType; //边上的权值类型应由用户定义
#define MAXVEX 100 //最大定点数
#define INFINITY 65535

typedef struct{
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵, 边表
    int numVertexes, numEdges; //当前图的顶点数和边数
}MGraph;

struct Edges{
    int index_begin; //边的起点下标
    int index_end; //边的终点下标
    EdgeType weight; //边的权值
    friend std::ostream& operator << (std::ostream &out, const Edges &edg){
        out << "(" << edg.index_begin << "," << edg.index_end << ")=" << edg.weight;
        return out;
    }
};
/* typedef struct Edg Edges; */


class Graph
{
private:
    MGraph mgraph;
    Edges edges[MAXVEX];
    

public:
    Graph();
    virtual ~Graph();
    Edges operator<<(const Edges &edg);
    void CreateMGraph(std::ifstream& infile); //创建无向图, 邻接矩阵表示法
    void CreateMGraph(); //创建无向图, 邻接矩阵表示法
    void MiniSpanTreePrim();// Prim算法实现最小生成树，适合稠密图
    void MiniSpanTreeKruskal();//Kruskal算法实现最小生成树，适合稀疏图
    void Adjvex2Edges();//邻接矩阵转换为边集数组
};


#endif
