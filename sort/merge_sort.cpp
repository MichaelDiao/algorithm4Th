#include <iostream>
#include <vector>

using namespace std;

template<class T>
void print_arr(const vector<T>& arr){
    for(auto x: arr){
        cout << x << "\t";
    }
    cout << endl << endl;
}

template<class T>
void merge(vector<T>& arr, int low, int mid, int high){
    vector<T> left(mid-low);
    vector<T> right(high-mid+1);

    for(int i=low; i<mid; ++i){
        left[i-low] = arr[i];
    }
    for(int i=mid; i<=high; ++i){
        right[i-mid] = arr[i];
    }
    /* for(int i=low; i <= high; ++i){ */
    /*     if(i<mid){ */
    /*         left[i-low] = arr[i]; */
    /*     }else{ */
    /*         right[i-mid] = arr[i]; */
    /*     } */
    /* } */

    int i = 0;
    int j = 0;
    int k = low;
    while(i<left.size() && j<right.size()){
        if(left[i] > right[j]){
            arr[k++] = right[j++];
        }else{
            arr[k++] = left[i++];
        }
    }

    for(; i<left.size(); ++i){
        arr[k++] = left[i];
    }
    for(; j<right.size(); ++j){
        arr[k++] = right[j];
    }

}

template<class T>
void merge_sort(vector<T>& arr, int low, int high){
    if(low >= high){
        return;
    }

    int mid = (high + low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    if(arr[mid] <= arr[mid+1]){
        return;
    }
    merge(arr, low, mid+1, high);
}

void merge2(int* arr, int low, int mid, int high){
    int LEFT_SIZE = mid - low;
    int RIGH_SIZE = high - mid + 1;
    int* left = new int(LEFT_SIZE);
    int* right = new int(RIGH_SIZE);

    int i, j, k;

    for(i=low; i<mid; ++i){
        left[i-low] = arr[i];
    }
    for(j=mid; j<=high; ++j){
        right[j-mid] = arr[j];
    }

    i = 0;
    j = 0;
    k = low;
    while(i<LEFT_SIZE && j<RIGH_SIZE ){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    while(i<LEFT_SIZE){
        arr[k++] = left[i++];
    }
    while(j<RIGH_SIZE){
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
    left = nullptr;
    right = nullptr;
}

void merge_sort2(int* arr, int low, int high){
    if(low >= high){
        return;
    }
    int mid = (high+low) / 2;
    merge_sort2(arr, low, mid);
    merge_sort2(arr, mid+1, high);
    merge2(arr, low, mid+1, high);
}


/**
* @brief: 自底向上方法归并，将数组先两两排序，再四四排序，，，直至跑完
*
* @param: 
*
* @return: void
*/
template<class T>
void merge_sort3(vector<T>& arr){
    for(int gap = 1; gap <= arr.size(); gap+=gap)
        for(int i=0; i+gap<arr.size(); i += 2*gap){
            merge(arr, i, i+gap, min(i+gap+gap-1, int(arr.size()-1)));
        }
}

int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    /* int a[8] = {6, 8, 10, 9, 4, 5, 2, 7}; */
    /* int a[11] = {13, 20, 26, 34, 38, 41, 9, 15, 17, 21, 30}; */
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    /* for(auto x: a){ */
    /*     cout << x << "\t"; */
    /* } */
    /* cout << endl; */
    print_arr(arr);

    cout << "start sorting" << endl;
    /* merge_sort2(a, 0, 7); */
    /* merge_sort(arr, 0, 10); */
    merge_sort3(arr);

    cout << "sorted arr: " << endl;
    /* for(auto x: a){ */
    /*     cout << x << "\t"; */
    /* } */
    /* cout << endl; */
    print_arr(arr);

    return 0;
}
