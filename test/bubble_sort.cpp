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

void bubble_sort(vector<int> &arr, bool reverse=false){
    bool sorted = true;
    for(size_t i=0; i<arr.size(); ++i){
        for(size_t j=1; j<arr.size()-i; ++j){
            //降序
            if(reverse){
                if(arr[j-1] < arr[j]){
                    swap(arr[j-1], arr[j]);
                    sorted = false;
                }
            }else{//升序
                if(arr[j-1] > arr[j]){
                    swap(arr[j-1], arr[j]);
                    sorted = false;
                }
            }
        }
        if(sorted){
            std::cout << "it is sorted!" << std::endl;
            break;//已经是有序，所以返回
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
    /* int a[] = {8, 15, 3, 32, 2, 20, 10, 11, 13, 5, 3, 7, 18, 22}; */
    int a[] = {8, 15, 22, 31, 33, 48, 52};
    vector<int> arr(a, a+7);
    std::cout << "before:" << std::endl;
    show(arr);
    bubble_sort(arr);
    std::cout << "after:" << std::endl;
    show(arr);

    return 0;
}
