/*************************************************************************
  > File Name   : test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月26日 星期二 19时08分57秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <memory>


using namespace std;

void show(vector<int> &arr){
    for(auto ele : arr)
        cout << ele << " ";
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right, shared_ptr<int []> tmp){
    int l_index = left;
    int r_index = mid;
    int tmp_index = left;
    while(l_index < mid && r_index <=right){
        if(arr[l_index] < arr[r_index])
            tmp[tmp_index++] = arr[l_index++];
        else
            tmp[tmp_index++] = arr[r_index++];
    }

    while(l_index < mid){
        tmp[tmp_index++] = arr[l_index++];
    }
    while(r_index <= right){
        tmp[tmp_index++] = arr[r_index++];
    }
    for(; left <=right; ++left){
        arr[left] = tmp[left];
    }
}



void MerSortRective(vector<int> &arr, int left,int right, shared_ptr<int []> tmp){
    if(right <= left)
        return;

    int mid = (left + right) / 2;
    MerSortRective(arr, left, mid, tmp);
    MerSortRective(arr, mid+1, right, tmp);
    merge(arr, left, mid+1, right, tmp);
}

void MerSort(vector<int> &arr, shared_ptr<int []> tmp){
    for(int len=1; len <= arr.size(); len = 2*len){
        for(int i=0; i+len < arr.size(); i += 2*len){
            int mid = i+len;
            int left = i;
            int right = min(i+2*len-1, int(arr.size()-1));
            merge(arr, left, mid, right, tmp);
        }
    }
}


void MergeSort(vector<int> &arr){
    if(arr.size() < 2){
        return;
    }
    shared_ptr<int []> tmp(new int[arr.size()]);
    /* MerSortRective(arr, 0, arr.size()-1, tmp); */
    MerSort(arr, tmp);

}




//堆排序 大顶堆

void adjust(vector<int> &arr, int index, int len){
    int value = arr[index];
    int child = 2*index+1; //left child
    int parent = index;
    while(child<len){
        //找到左右孩子中最大的孩子
        if(child+1 < len && arr[child] < arr[child+1])
            child = child + 1;

        //判断最大子孩子是否比当前的父节点小，如果小，说明不需要继续向下调整，直接结束调整
        if(value > arr[child])
            return;

        arr[parent] = arr[child];
        parent = child;
        child = 2*child+1;//继续向下调整
    }
    arr[parent] = value;
}

void HeapSort(vector<int> &arr){
    int len = arr.size();
    //建立大顶堆
    for(int i=len/2-1; i>=0; --i){
        adjust(arr, i, len);
    }

    for(int i=0; i<len; ++i){
        swap(arr[0], arr[len-1-i]);
        adjust(arr, 0, len-i);
    }
}

int getMid(vector<int> &arr, int left, int right){
    int mid = (left+right)/2;
    if(arr[mid] > arr[left])
        swap(arr[left], arr[mid]);
    if(arr[right] > arr[left])
        swap(arr[left], arr[right]);
    if(arr[right] > arr[mid])
        swap(arr[right], arr[mid]);
    return mid;
}

int partition(vector<int> &arr, int left, int right){
    int pivotkey = getMid(arr, left,right);
    swap(arr[left], arr[pivotkey]);
    int comp = arr[left];
    int l = left+1;
    int r = right;


    while(1){
        while( r > l && arr[r] > comp) --r;
        /* swap(arr[l], arr[r]); */
        while( l < r && arr[l] < comp) ++l;
        if(l>=r)
            break;
        swap(arr[l++], arr[r--]);
    }
    swap(arr[r], arr[left]);
    return r;
}

void qSort(vector<int> &arr, int left, int right){
    if(right <= left)
        return;

    int mid = partition(arr, left, right);
    qSort(arr, left, mid-1);
    qSort(arr, mid+1, right);
}

void QuickSort(vector<int> &arr){
    qSort(arr, 0, arr.size()-1);
}


int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw:" << endl;
    show(arr);
    /* MergeSort(arr); */
    QuickSort(arr);
    cout << "after:" << endl;
    show(arr);
    

    return 0;
}
