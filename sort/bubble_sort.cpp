#include <iostream>
#include <vector>

using namespace std;

// 原始冒泡排序
// reverse = false, default is increase sort, or decrease
template<class T>
void Bubble_Sort1(vector<T>& arr, bool reverse=false){
    int i=0;
    for( typename vector<T>::iterator iter = arr.begin(); iter != arr.end(); ++iter, ++i){
        for(typename vector<T>::iterator iter2 = arr.begin(); iter2 != arr.end()-i-1; ++iter2){
            //increase sort
            if(!reverse){
                if (*iter2 > *(iter2+1)) 
                    swap(*iter2, *(iter2+1));
            }else{// decrease sort
                if (*iter2 < *(iter2+1))  
                    swap(*iter2, *(iter2+1));
            }
        }
        cout << "********" << endl;
        for(auto &it: arr)
            cout << it << "\t";
        cout << endl << endl;
    }
}

//改进后的冒泡排序
// 使用标志位标识第一次遍历是否发生交换；使用高低指针进行双向交换
template<class T>
void Bubble_Sort2(vector<T>& arr, bool reverse=false){
    typename vector<T>::iterator beg = arr.begin();
    typename vector<T>::iterator end = arr.end();

    while(beg < end){
        bool change_flag = false;
        for(auto it = beg; it != end-1; ++it){
            if(!reverse){
                if(*it > *(it+1)){
                    swap(*it, *(it+1));
                    change_flag = true;
                }
            }else{
                if(*it < *(it+1)){
                    swap(*it, *(it+1));
                    change_flag = true;
                }
            }
        }
        cout << "end************" << endl;
        for(auto &it: arr)
            cout << it << "\t";
        cout << endl;
        --end;
        //注意，这里不是beg-1， 因为vector.end()指向的是最后一个元素的后面结束符
        //而begin指向的是vec的第一个元素，因此这里终止条件是it!=beg,
        for(auto it = end; it != beg; --it){
            if(!reverse){
                if(*it < *(it-1)){
                    swap(*it, *(it-1));
                    change_flag = true;
                }
            }else{
                if(*it > *(it-1)){
                    swap(*it, *(it-1));
                    change_flag = true;
                }
            }
        }
        cout << "beg************" << endl;
        for(auto &it: arr)
            cout << it << "\t";
        cout << endl << endl;
        ++beg;
        //如果没发生改变，表示数组本来就是有序的，所以直接退出即可
        if(!change_flag){
            cout << "it's a sorted array" << endl;
            break;
        }
    }

}

int main(int argc, char *argv[])
{
    /* int array[10] = {5, 6, 8, 3, 0, 8, 5, 14, 1, 9}; */
    int array[10] = {0, 1, 3, 5, 5, 6, 8, 9, 9, 14};
    vector<int> arr(array, array+10);
    cout << "before sort" << endl;
    for(auto &item: arr){
        cout << item << ", ";
    }
    cout << endl << "-----------------" << endl;

    Bubble_Sort1(arr, true);


    cout << "sorted array: " << endl;
    for(auto &item: arr){
        cout << item << ", ";
    }
    cout << endl;

    return 0;
}

