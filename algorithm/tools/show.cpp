#include <iostream>
#include <algorithm>
#include "show.h"

void show_arr(const int arr[], int len){
    std::cout << "arr: " << std::endl;
    std::for_each(arr, arr+len, [](int x){std::cout << x << "\t";});
    std::cout << std::endl;
}
