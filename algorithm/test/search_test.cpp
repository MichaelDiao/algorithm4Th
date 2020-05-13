/*************************************************************************
  > File Name   : test/search_test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月12日 星期二 14时17分16秒
 ************************************************************************/
#include<iostream>
#include "search.h"

using namespace std;


int main(int argc, char *argv[])
{
    /* vector<int> arr = {21, 21, 22, 26, 30, 39, 53, 57, 59, 64}; */
    vector<int> arr = {21, 21, 21, 21, 21, 21, 21, 24, 28, 36};
    Search test_search(arr);
    /* int res = test_search.FibonacciSearch(39); */
    /* int res = test_search.BinarySearch(79); */
    int res = test_search.InsertValueSearch(24);

    std::cout << "res = " << res << std::endl;
    

    return 0;
}
