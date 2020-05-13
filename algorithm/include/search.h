/*************************************************************************
  > File Name   : search.h
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月12日 星期二 10时57分09秒
 ************************************************************************/

#ifndef _SEARCH_H
#define _SEARCH_H

#include <vector>

class Search{
    public:
        Search(const int num); 
        Search(std::vector<int> &vec);
        ~Search();
        int FibonacciSearch(const int target); //斐波那契查找
        int BinarySearch(const int target) const; //二分查找
        int InsertValueSearch(const int target) const; //插值查找
    private:
        std::vector<int> arr;
        static int Fibonacci[10]; //斐波那契数列
};

#endif
