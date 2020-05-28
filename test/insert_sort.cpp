/*************************************************************************
  > File Name   : bubble_sort.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月19日 星期二 16时45分38秒
 ************************************************************************/
#include<iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int> &arr, bool reverse=false){
    for(int i=1; i<arr.size(); ++i){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            --j;
        }
    }
}

void show(vector<int> &arr){
    for(auto ele : arr){
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    /* int a[] = {8, 15, 22, 31, 33, 48, 52}; */
    /* vector<int> arr(a, a+7); */
    int a[] = {8, 15, 3, 32, 2, 20, 10, 11, 13, 5, 3, 7, 18, 22};
    vector<int> arr(a, a+14);
    std::cout << "before:" << std::endl;
    show(arr);
    insert_sort(arr);
    std::cout << "after:" << std::endl;
    show(arr);

    return 0;
}
