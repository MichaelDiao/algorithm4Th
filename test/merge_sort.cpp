/*************************************************************************
  > File Name   : test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年05月20日 星期三 21时29分36秒
 ************************************************************************/
#include<iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

void show(vector<int> &arr){
    for(auto ele : arr){
        cout << ele << " ";
    }
    cout << endl;
}
void show(shared_ptr<int []> arr, int len){
    for(int i=0; i<len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
void merge(vector<int> &arr, shared_ptr<int []> tmp, int left, int right, int mid){
    int tmp_index = left;
    int left_index = left;
    int right_index = mid;
    while(left_index < mid && right_index <= right){
        if(arr[left_index] < arr[right_index]){
            tmp[tmp_index++] = arr[left_index++];
        }else{
            tmp[tmp_index++] = arr[right_index++];
        }
    }

    while(left_index < mid){
        tmp[tmp_index++] = arr[left_index++];
    }
    while(right_index <= right){
        tmp[tmp_index++] = arr[right_index++];
    }

    while(left <=right){
        arr[left] = tmp[left];
        ++left;
    }
}


void merge_sort(vector<int> &arr, shared_ptr<int []> tmp, int left, int right){
    if(right <= left)
        return;

    int mid = (left + right) / 2;
    merge_sort(arr, tmp, left, mid);
    merge_sort(arr, tmp, mid+1, right);
    merge(arr, tmp, left, right, mid+1);
    cout << "left=" << left << ", right=" << right << ", mid=" << mid << ", tmp: " << endl;
    show(tmp, arr.size());
    cout << "---------------------" << endl;
}

void merge_sort(vector<int> &arr, shared_ptr<int []> tmp){
    for(int len = 1; len <= arr.size(); len+=len){
        for(int i=0; i+len < arr.size(); i += 2*len){
            int right = min(i+len+len-1, int(arr.size()-1));
            int mid = i+len;
            merge(arr, tmp, i,  right, mid);
            show(tmp, arr.size());
        }
    }
}


void MergeSort(vector<int> &arr){
    shared_ptr<int []> tmp(new int[arr.size()]);
    merge_sort(arr, tmp, 0, arr.size()-1);
    /* merge_sort(arr, tmp); */
    /* for(int i=0; i<arr.size(); ++i){ */
    /*     arr[i] = tmp[i]; */
    /* } */
}



int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 2};
    vector<int> arr(a, a+11);
    /* int a[5] = {3, 2, 4, 1, 8}; */
    /* vector<int> arr(a, a+5); */
    cout << "start" << endl;
    MergeSort(arr);
    cout << "sorted: " << endl;
    show(arr);

    return 0;
}
