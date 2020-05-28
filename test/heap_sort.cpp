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

void adjustHead(vector<int> &arr, int index, const int len){
    int tmp = arr[index];
    //因为下标从0开始，所以lchild= 2*parent+1, rchild=2*parent+2
    int child = index * 2 + 1;

    while(child < len){
        if(child + 1 < len && arr[child] < arr[child+1]){
            ++child;//右孩子最大，所以指向右孩子
        }
        //调整值与最大孩子比较
        //如果孩子更大，则需要继续向下遍历二叉树， 否则直接跳出循环
        if(tmp > arr[child]){
           break; 
        }
        arr[index] = arr[child]; //将当前最大值赋值到调整点处 
        index = child; //index 始终指向子树的最大节点
        child = 2 * child + 1;//找到当前最大的孩子的左孩子
    }
    arr[index] = tmp;//最后child是最大点处，该值已经赋值给调整点处，所以调整点处的值应该放在这里
}


void heap_sort(vector<int> &arr, bool reverse=false){
    int len = arr.size();
    for(int i=len/2-1; i>=0; --i){
        adjustHead(arr, i, len);
        std::cout << "len=" << len << ", i=" << i << std::endl;
        show(arr);
    }

    std::cout << "sorting:" << std::endl;
    for(; len>0; --len){
        swap(arr[0], arr[len-1]);
        adjustHead(arr, 0, len-1);
        show(arr);
    }
    
}

int main(int argc, char *argv[])
{
    /* int a[] = {8, 15, 22, 31, 33, 48, 52}; */
    /* vector<int> arr(a, a+7); */
    /* int a[] = {8, 15, 3, 32, 2, 20, 10, 11, 13, 5, 3, 7, 18, 22}; */
    /* vector<int> arr(a, a+14); */
    int a[] = {2, 7, 8, 2, 1, 4, 5, 3, 9};
    vector<int> arr(a, a+9);
    std::cout << "before:" << std::endl;
    show(arr);
    heap_sort(arr);
    std::cout << "after:" << std::endl;
    show(arr);

    return 0;
}
