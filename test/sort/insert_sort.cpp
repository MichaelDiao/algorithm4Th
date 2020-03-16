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
void insert_sort(vector<T>& arr){
    for(int i=1; i < arr.size(); ++i){
        for(int j=i; j >= 0; --j){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
            }else{
                break;
            }
        }
        cout << "------------" << endl;
        print_arr(arr);
    }
}

int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);

    cout << "start sorting" << endl;
    insert_sort(arr);

    return 0;
}
