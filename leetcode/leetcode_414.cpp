/*************************************************************************
  > File Name   : leetcode_414.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年04月24日 星期五 19时57分07秒
 ************************************************************************/
#include<iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            if(nums.size() < 3){
                long max = LONG_MIN;
                for(int i = 0; i < nums.size(); ++i){
                    if(max < nums[i]){
                        max = nums[i];
                    }
                }
                return max;
            }
            long max = LONG_MIN;
            long second_max = LONG_MIN;
            long third_max = LONG_MIN;

            for(int i = 0; i < nums.size(); ++i){
                if(max < nums[i]){
                    third_max = second_max;
                    second_max = max;
                    max = nums[i];
                }else if(max != nums[i] && nums[i] > second_max){
                    third_max = second_max;
                    second_max = nums[i];
                }else if(max != nums[i] && second_max != nums[i] && nums[i] > third_max){
                    third_max = nums[i];
                }
            }

            std::cout << "max:" << max << ", second_max: " << second_max << std::endl;

            return third_max == LONG_MIN ? int(max) : int(third_max);

        }
};


int main(int argc, char *argv[])
{
    /* vector<int> nums = {1,2,-2147483648}; */
    vector<int> nums = {3, 2, 3, 78, 23, 22, 0, -12, 1};
    Solution slu;
    int third_max = slu.thirdMax(nums);

    std::cout << LONG_MIN << std::endl;

    std::cout << "third_max=" << third_max << std::endl;
    set<int> dict(nums.begin(), nums.end());
    for(int item: dict){
        std::cout << item << std::endl;
    }
    

    return 0;
}
