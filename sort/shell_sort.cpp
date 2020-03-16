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
void shell_sort(vector<T>& arr){
    int size = arr.size();
    int gap = 1;
    while(gap < size/3){
        gap = 3*gap + 1;
    }
    
    while(gap >= 1){
        cout << "------gap=" << gap <<endl;
        for(int i=gap; i < size; ++i){
            for(int j=i; j>=gap && (arr[j] < arr[j-gap]); j-=gap){
                swap(arr[j], arr[j-gap]);
            }
            print_arr(arr);
        }
        gap /= 3;
    }
}

int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);

    cout << "start sorting" << endl;
    shell_sort(arr);

    return 0;
}
