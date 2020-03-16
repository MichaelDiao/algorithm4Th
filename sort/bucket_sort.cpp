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
void bucket_sort(T begin, T end){
    int bucket[34] = {0};
    for(T it=begin; it<end; ++it){
        bucket[*it]++;
    }

    T it=begin;
    for(int i=0; i<34; ++i){
        for(int j=bucket[i];  j>0; --j){
            *(it++) = i;
        }
    }
}

int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);

    cout << "start sorting" << endl;
    bucket_sort(arr.begin(), arr.end());
    cout << "sorted arr:" << endl;
    print_arr(arr);

    return 0;
}
