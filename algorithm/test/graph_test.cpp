/*************************************************************************
  > File Name   : test/graph_test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月07日 星期四 16时46分46秒
 ************************************************************************/
#include "graph.h"
#include<iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    ifstream infile;
    infile.open("test/graph_data.txt", ios::in);


    Graph graph;
    graph.CreateMGraph(infile);
    graph.MiniSpanTreePrim();
    cout << "---------------------\n\n" << endl;
    graph.MiniSpanTreeKruskal();

    
    infile.close();

    return 0;
}
