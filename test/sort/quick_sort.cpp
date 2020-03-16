#include<vector>
#include <iostream>

using namespace std;


template<class T>
int partition(vector<T>& arr, int low, int high)
{
    T compar = arr[low];
    int i = low+1;
    int j = high;
    while(1){
        while((arr[j] < compar) && j > low){
            --j;
        }
        while((arr[i] > compar) && i < high){
            ++i;
        }
        if(i >= j){
            break;
        }
        swap(arr[i++], arr[j--]);
    }
    swap(arr[j], arr[low]);

    return j;
}

/******************************************************************************
* Function:         void quick_sort(vector<T>& arr, int low, int high
* Description:      
* Where:
* Return:           
* Error:            
*****************************************************************************/
template<class T>
void quick_sort(vector<T>& arr, int low, int high){
    if(low >= high)
        return;
    int cur_ind = partition(arr, low, high);
    quick_sort(arr, low, cur_ind-1);
    quick_sort(arr, cur_ind+1, high);
}

/******************************************************************************
* Function:         void quick_sort2
* Description:vector<T>& arr, int low, int high 
* Where:当数组中存在大量相等的数据时，使用普通快排将存在对相等的数据调用递归，
* 因此这里采用三分法进行优化。
* Return:           
* Error:            
*****************************************************************************/
template<class T>
void quick_sort2(vector<T>& arr, int low, int high){
    if(low >= high){
        return;
    }
    
    T compar = arr[low];
    int lt = low;//小于切分元素的索引
    int cur = low + 1; //等于切分元素的索引
    int gt = high;//大于切分元素的索引
    while(cur <= gt){
        if(arr[cur] < compar){
            swap(arr[cur++], arr[lt++]);
        }else if(arr[cur] > compar){
            swap(arr[cur], arr[gt--]);
        }else{
            ++cur;
        }
    }
    cout << endl << endl << "cur:" << cur << ",item:" << arr[cur] << ",com:" << compar << " tmp arr" << endl;
    for(auto x: arr){
        cout << x << "\t";
    }
    cout << endl;
    quick_sort2(arr, low, lt-1);
    quick_sort2(arr, gt+1, high);
}

int main(int argc, char *argv[])
{
    /* int a[10] = {9, 21, 4, 8, 1, 9, 5, 7, 11, 0}; */
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    /* int a[5] = {9, 21, 4, 8, 1}; */
    vector<int> arr(a, a+11);

    quick_sort2(arr, 0, arr.size()-1);

    cout << "arr: " << endl;
    for(auto &x: arr){
        cout << x << '\t';
    }
    cout << endl;
    

    return 0;
}
