#include <iostream>
#include <vector>

using namespace std;

template<class T>
void print_arr(const vector<T>& arr){
    for(auto x: arr){
        cout << x << '\t';
    }
    cout << endl << endl;
}


template<class T>
void select_sort(vector<T>& arr){
    int min_index = 0;

    for(int i=0; i < arr.size()-1; ++i){
        min_index = i;
        for(int j=i; j < arr.size(); ++j){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
        cout << "---------------min=" << min_index << endl;
        print_arr(arr);
    }
}

template<class T>
void select_sort2(vector<T>& arr){
    int min_index = 0;
    int max_index = arr.size()-1;

    for(int i=0; i < arr.size()-1-i; ++i){
        min_index = i;
        for(int j=i; j < arr.size()-i; ++j){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
            if(arr[j] > arr[max_index]){
                max_index = j;
            }
        }
        if(i == max_index){
            T tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = arr[arr.size()-i-1];
            arr[arr.size()-i-1] = tmp;
        }else{
            swap(arr[i], arr[min_index]);
            swap(arr[arr.size()-i-1], arr[max_index]);
        }
        cout << "---------------min=" << min_index << ",max=" << max_index << endl;
        print_arr(arr);
    }
}


int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);


    select_sort2(arr);
    cout << "sorted arr: " << endl;
    print_arr(arr);

    return 0;
}
