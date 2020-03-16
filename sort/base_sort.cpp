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
int getMaxBit(T begin, T end){
    int maxnum = -1;
    for(T it=begin; it<end; ++it){
        maxnum = maxnum > *it ? maxnum : *it;
    }


    int maxbit = 1;
    while(maxnum >= 10){
        maxbit++;
        maxnum /= 10;
    }

    return maxbit;
}


template<class T>
void base_sort(T begin, T end){
    int maxbit = getMaxBit(begin, end);
    cout << "end-begin:" << end-begin << endl;
    int* tmp = new int[end-begin];
    int* count = new int[10]();
    int raido = 1;
    int k=0;

    for(int i=0; i<maxbit; ++i){
        //每次都需要清空数组
        for_each(count, count+10, [](int& x){x=0;});

        //按照每一位数字大小放入count中
        for(T it=begin; it<end; ++it){
            k = (*it / raido) % 10;
            //ascendin sort
            count[k]++;
            //descending sort
            /* count[9-k]++; */
        }

        //累加数组，数组下标表示基数数值a，对应的下标x和x-1的value差值cnt表示在当前数组中，当前基数位为a的数字一共有cnt个。
        for(int f=1; f<10; ++f){
            count[f] += count[f-1];
        }

        //根据累加数组的特性，倒序遍历原始数组，可依次按照基数个数将其放到正确位置，暂存在tmp中
        for(T it=end-1; it>=begin; --it){
            k = (*it / raido) % 10;
            //ascending sort
            tmp[count[k]-1] = *it;
            count[k]--;
            //descending sort
            /* tmp[count[9-k]-1] = *it; */
            /* count[9-k]--; */
        }
        //统计完后，将tmp中复制到原始数组中
        for(int j=0; j<end-begin; ++j){
            *(begin+j) = tmp[j];
        }
        //以更高一位进行排序
        raido *= 10;
    }
    cout << endl << "assum array:" << endl;
    /* for_each(count, count+10, [](int& x){cout << x << "\t";}); */
    cout << endl;

    delete[] count;
    count = nullptr;
    delete[] tmp;
    tmp = nullptr;
}

int main(int argc, char *argv[])
{
    int a[11] = {32333, 21, 21, 4, 8, 21, 9, 5, 7, 21, 0};
    vector<int> arr(a, a+11);
    cout << "raw arr: " << endl;
    print_arr(arr);

    clock_t begin, end;
    cout << "start sorting" << endl;
    begin = clock();
    int res = getMaxBit(arr.begin(), arr.end());
    base_sort(arr.begin(), arr.end());
    end = clock();
    cout << res << " sorted arr:" << endl;
    print_arr(arr);

    cout << "cost time: " << (double)(end-begin)/CLOCKS_PER_SEC*1000000 << "us" << endl;

    return 0;
}
