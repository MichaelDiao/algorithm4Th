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

void show(const vector<int> &arr){
    for(auto ele : arr){
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void shell_sort(vector<int> &arr, bool reverse=false){
    std::cout << "arr size=" << arr.size() << std::endl;
    int gap = 1;
    while(gap < arr.size() / 3){
        gap = gap * 3 + 1;
    }
    for(; gap > 0; gap /= 3){
        for(int i=gap; i<arr.size(); ++i){
            int k = i;
            while(k >= gap && arr[k] < arr[k-gap]){
                swap(arr[k], arr[k-gap]);
                k -= gap;
            }
        }
        std::cout << "gap=" << gap << std::endl;
        show(arr);
    }
}

int main(int argc, char *argv[])
{
    /* int a[] = {8, 15, 22, 31, 33, 48, 52}; */
    /* vector<int> arr(a, a+7); */
    int a[] = {2, 12, 13, 6, 9, 30, 0, 8, 15, 3, 32, 2, 20, 10, 11, 13, 5, 3, 7, 18, 22};
    vector<int> arr(a, a+21);
    std::cout << "before:" << std::endl;
    show(arr);
    shell_sort(arr);
    std::cout << "after:" << std::endl;
    show(arr);

    return 0;
}
