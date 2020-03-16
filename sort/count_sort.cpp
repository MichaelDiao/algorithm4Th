#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

template<class T>
void print_arr(const vector<T>& arr){
    for(auto x: arr){
        cout << x << "\t";
    }
    cout << endl << endl;
}



template<class T>
void count_sort(vector<T>& arr){
    T maxnum=arr[0];
    T minnum=arr[0];
    for_each(arr.begin(), arr.end(), [&](T x){
            maxnum = maxnum < x ? x : maxnum;
            minnum = minnum > x ? x : minnum;});

    int* count = new int[maxnum-minnum+1]();
    
    for_each(arr.begin(), arr.end(), [&count, minnum](T x){count[x-minnum]++;});

    for(int i=1; i<maxnum-minnum+1; ++i){
        count[i] += count[i-1];
    }

    T* tmp = new T[arr.size()]();
    for(int i=arr.size()-1; i>=0; --i){
        tmp[count[arr[i]-minnum]-1] = arr[i];
        count[arr[i]-minnum]--;
    }
    
    int i=0;
    //ascending sort
    for_each(tmp, tmp+arr.size(), [&arr, &i](T x){arr[i++]=x;});
    //descending sort
    /* for_each(tmp, tmp+arr.size(), [&arr, &i](T x){arr[(arr.size()-i-1)]=x;++i;}); */


    delete[] count;
    delete[] tmp;
    count=nullptr;
    tmp=nullptr;
}

int main(int argc, char *argv[])
{
    int a[11] = {33, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);

    clock_t begin, end;
    cout << "start sorting" << endl;
    begin = clock();

    // do something....
    count_sort(arr);



    end = clock();
    cout << " sorted arr:" << endl;
    print_arr(arr);

    cout << "cost time: " << (double)(end-begin)/CLOCKS_PER_SEC*1000000 << "us" << endl;

    return 0;
}
