#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void print_arr(const int arr[], const int size){
    for_each(arr, arr+size, [](int item){cout << item << "\t";});
    cout << endl << endl;
}


void heapify(int arr[], const int size, const int index){
    if(index >=size)
        return;
    int l_node = (2 * index) + 1;
    int r_node = (2 * index) + 2;
    int min_index = index;

    if(l_node < size && arr[min_index] > arr[l_node]){
        min_index = l_node;
    }
    if(r_node < size && arr[min_index] > arr[r_node]){
        min_index = r_node;
    }
    if(min_index != index){
        swap(arr[index], arr[min_index]);
        /* static int cnt = 0; */
        /* cout << "cur: " << cnt++ << endl; */
        /* cout << "index: " << index << ", max_index: " << max_index << endl; */
        /* print_arr(arr, size); */
        heapify(arr, size, min_index);
    }
}


void build_heap(int arr[], const int size){
    for(int i=size-1; i>=0; --i){
        int parent_node = (i - 1) / 2;
        heapify(arr, size, parent_node);
    }
}

void heap_sort(int arr[], const int size){
    build_heap(arr, size);
    for(int i=size-1; i>=0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main(int argc, char *argv[])
{
    /* int a[11] = {3, 21, 9, 4, 8, 21, 21, 5, 7, 21, 0}; */
    int a[11] = {3, 11, 19, 24, 28, 31, 31, 35, 37, 41, 50};
    cout << "raw arr: " << endl;
    print_arr(a, 11);

    clock_t begin, end;
    cout << "start sorting" << endl;
    begin = clock();
    heap_sort(a, 11);
    end = clock();

    cout << "sorted arr: " << endl;
    print_arr(a, 11);

    cout << "cost time: " << (double)(end-begin)/CLOCKS_PER_SEC * 1000 * 1000 << "us" << endl;
    return 0;
}
