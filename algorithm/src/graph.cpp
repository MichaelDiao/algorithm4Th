/*************************************************************************
  > File Name   : src/graph.cpp
  > Desc      : 图的创建、遍历、最小生成树等算法
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月07日 星期四 15时08分21秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include "graph.h"

Graph::Graph(){
    for(auto &row: mgraph.arc){
        for(auto &edge: row){
            edge = INFINITY;
        }
    }
    for(VertexType &vertex: mgraph.vexs){
        vertex = 0;
    }
    for(auto &ele : edges){
        ele.index_begin = 0;
        ele.index_end = 0;
        ele.weight = 0;
    }
}

Graph::~Graph(){

}

//邻接矩阵
void Graph::CreateMGraph(){
    std::cout << "input the number of vertex and the edges: " << std::endl;
    std::cin >> mgraph.numVertexes >> mgraph.numEdges;
    std::cout << "input the info of vertex" << std::endl;

    for(int i=0; i<mgraph.numVertexes; ++i){
        std::cin >> mgraph.vexs[i];
    }

    std::cout << "intput the info of edges:" << std::endl;
    int i = 0;
    int j = 0;
    int w = 0;
    for (int k = 0; k < mgraph.numEdges; ++k) {
        std::cout << "输入边(Vi, Vj)的下标i, j以及权重w:" << std::endl;
        std::cin >> i >> j >> w;
        std::cout << "i=" << i << ",j=" << j << ",k=" << w << std::endl;
        mgraph.arc[i][j] = w;//无向图，因此是对称矩阵
        mgraph.arc[j][i] = w;
    }
}


//邻接矩阵
void Graph::CreateMGraph(std::ifstream& infile){

    int cur_line_num = 1;
    int value = 0;
    int edges = 0;
    while(!infile.eof() && infile.peek() != EOF){
        if(cur_line_num < 2){
            infile >> mgraph.numVertexes >> mgraph.numEdges;
            std::cout << "value:=" << value << ", edges=" << edges << std::endl;
        }else{
            int i = 0;
            int j = 0;
            int w = 0;
            infile >> i >> j >> w;
            std::cout << "i=" << i << ", j=" << j << ", w=" << w << std::endl;
            mgraph.arc[i][j] = w;//无向图，因此是对称矩阵
            mgraph.arc[j][i] = w;
        }
        ++cur_line_num;
        infile.get();
    }
    std::cout << "line num=" << --cur_line_num << std::endl;
    std::cout << "input the info of vertex" << std::endl;

    std::cout << "vertex is :" << std::endl;
    for(int i=0; i<mgraph.numVertexes; ++i){
        mgraph.vexs[i] = 97 + i;
        std::cout << mgraph.vexs[i] << "\t";
    }
    std::cout << std::endl;

}
//Prim算法实现最小生成树
void Graph::MiniSpanTreePrim(){
    int min, i, j, k;
    int adjvex[MAXVEX] = {0}; //保存相关顶点的下标
    int lowcost[MAXVEX] = {0}; //保存相关顶点间边的权值

    lowcost[0] = 0; //初始化第一个权值为0， 即V0加入生成树

    adjvex[0] = 0; //初始化第一个定点下标为0
    for (i = 0; i < mgraph.numVertexes; ++i) {
        lowcost[i] = mgraph.arc[0][i]; //将V0顶点与之右边的权值存入数组中
    }

    for (i = 1; i < mgraph.numVertexes; ++i) {
        min = INFINITY; //初始化最小的权值为无穷大

        j = 1;
        k = 0;
        while(j < mgraph.numVertexes){
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];// 让当前权值成为最小值
                k = j; //将当前最小值的下标存入k
            }
            ++j;
        }
        std::cout << "(" << adjvex[k] << ", " << k << ")" << std::endl;
        lowcost[k] = 0;
        for (j = 0; j < mgraph.numVertexes; ++j) {
             if(lowcost[j] != 0 && mgraph.arc[k][j] < lowcost[j]){
                 lowcost[j] = mgraph.arc[k][j];
                 adjvex[j] = k;
             }
        }
    }
}

int FindEnd(int parent[], int index){
    while(parent[index] > 0){
        index = parent[index];
    }
    return index;
}

//Krusal算法实现最小生成树， 适用于稀疏图 时间复杂度O(eloge), e为边数
void Graph::MiniSpanTreeKruskal(){
    Adjvex2Edges();
    int parent[MAXVEX] = {0}; //存储最小生成树的边的顶点

    std::cout << "\n\nminispantree kruskal: " << std::endl;
    for(int i=0; i<mgraph.numEdges; ++i){
        int n = FindEnd(parent, edges[i].index_begin);
        int m = FindEnd(parent, edges[i].index_end);

        if(n != m){
            parent[n] = m;
            std::cout << "edges " << i << " : " << edges[i] << std::endl;
        }
    }
    
}



bool CompareWeight(Edges i, Edges j){
    return i.weight < j.weight;
}

//邻接矩阵转换为边集数组
void Graph::Adjvex2Edges(){
    int cnt = 0;
    for (int i = 0; i < mgraph.numEdges; ++i) {
        for (int j = i + 1; j < mgraph.numEdges; ++j) {
            if(mgraph.arc[i][j] >= INFINITY)
                continue;
            Edges one_edge;
            one_edge.index_begin = i;
            one_edge.index_end = j;
            one_edge.weight = mgraph.arc[i][j];
            edges[cnt++] = one_edge;
        }
    }

    std::sort(edges, edges+mgraph.numEdges, CompareWeight);

    int i = 0;
    for(auto &ele : edges){
        std::cout << "edge" << i << " : (" << ele.index_begin << "," << ele.index_end << ")=" << ele.weight << std::endl;
        if(++i == mgraph.numEdges)
            break;
    }
}
