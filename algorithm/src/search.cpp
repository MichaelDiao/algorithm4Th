/*************************************************************************
  > File Name   : search.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月12日 星期二 10时56分56秒
 ************************************************************************/
#include "search.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

int Search::Fibonacci[10] = {0};

Search::~Search(){

}

Search::Search(const int num){
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for(int i=2; i<10; ++i){
        Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];
    }
    std::cout << "Fibonacci:" << std::endl;
    for(auto ele : Fibonacci){
        std::cout << ele << "\t";
    }
    std::cout << std::endl;

    //产生随机数组
    srand(time(NULL));

    for(int i=0; i<num; ++i){
        arr.push_back(rand() % 100);
    }
    std::sort(arr.begin(), arr.end());
    std::cout << "arr:" << std::endl;
    for(auto ele : arr){
        std::cout << ele << "\t";
    }
    std::cout << std::endl;

}


Search::Search(std::vector<int> &vec){
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for(int i=2; i<100; ++i){
        Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];
    }
    std::cout << "Fibonacci:" << std::endl;
    for(auto ele : Fibonacci){
        std::cout << ele << "\t";
    }
    std::cout << std::endl;

    arr = std::move(vec);
    std::cout << "arr:" << std::endl;
    for(auto ele : arr){
        std::cout << ele << "\t";
    }
    std::cout << std::endl;
}


int Search::FibonacciSearch(const int target){
    size_t size = arr.size();
    int index_fib = 0;

    //找到当前arr数组长度在fib数列中的位置，确定该位置的下标index_fib
    while(Fibonacci[index_fib] < int(size)){
        ++index_fib;
    }
    std::cout << "index=" << index_fib << std::endl;

    //假设arr长度为Finboncci[index_fib], 超出原来大小的部分用最后一个数字填充
    //用最后一个数字补全Fibonacci[index_fib] - size + 1 这一部分的数据，以免使用fib的索引进行遍历时出现越界访问
    for(int i=size; i<Fibonacci[index_fib]; ++i){
        arr.push_back(arr[size-1]);
    }

    int mid = 0;
    int left = 0;
    int right = size - 1;

    while(left <= right){
        //根据fib数列性质：Fib[index] = Fib[index-1] + Fib[index-2],
        //即长度为Fib[index]的数列可以分为长度为Fib[index-1]和Fib[index-2]两部分
        //将当前arr分为长度为Fibonicci[index_fib-1]和Fibonicci[index_fib-2]两部分
        mid = left + Fibonacci[index_fib-1] - 1;//这里减1是因为fib[index_fib]中已经包括了下标为left的这个数，所以需要减去这个重复数
        std::cout << "left=" << left << ", right=" << right << ", index=" << index_fib << ", arr[" << mid << "] = " << arr[mid] << std::endl;
        if(arr[mid] > target){
            //当前mid对应的arr值<target, 表明target在arr的[left, Fibonacci[index_fib-1]-1+left]
            //因此当前区间又可以分为两部分F[i-1]+F[i-2]两部分, 仍然在F[i-1]这部分中找
            right = mid - 1;
            index_fib -= 1;
        }else if(arr[mid] < target){
            left = mid + 1;
            index_fib -= 2;
        }else{
            return mid;
        }
    }


    return -1; 
}


//二分查找
int Search::BinarySearch(const int target) const{
    int left = 0;
    int right = (int)arr.size() - 1;
    int mid = (left + right) / 2;

    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] > target){
            right = mid - 1;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}


//插值查找
int Search::InsertValueSearch(const int target) const{
    int size = (int)arr.size() - 1;
    int left = 0;
    int right  = size;
    int mid = 0;

    //插值查找必须保证目标值在数组中的最小值和最大值之间
    if(target > arr[size] || target < arr[0])
        return -1;

    while(arr[left] != arr[right] && left <= right){
        mid = left + (right - left) * fabs(target - arr[left]) / (arr[right] - arr[left]) ;
        std::cout << "l=" << left << ", r=" << right << ", m=" << mid << std::endl;
        if(arr[mid] > target){
            right = mid - 1;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}

