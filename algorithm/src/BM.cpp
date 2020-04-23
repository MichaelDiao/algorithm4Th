#include <iostream>
#include "BM.h"

#define MAX(x, y) (x) > (y) ? (x) : (y);

/*****************************************************************
* @brief: 根据坏字符数组规则构建badchar
* @param: 
*	badCharArr: 存放patt中每个字符在最右边的位置
* @retrun:  retrun
* @comment:  -
*****************************************************************/
void buildBadCharArr(const std::string& patt, int* badCharArr){
    int len = int(patt.size());
    for (int i = 0; i < 256; ++i) {
        badCharArr[i] = len; 
    }

    //注意这里是<len-1, 如果i<len,则i=len-1时，此时badCharArr[patt[i]] = 0, 根据
    //坏字符规则，模式串匹配时，移动距离变成负数，导致模式串回退，这是不合理的
    for (int i = 0; i < len - 1; ++i) {
        badCharArr[int(patt[i])] = len - 1 - i;
    }


    for (int i = 0; i < len; ++i) {
        if(i % 15 == 0){
            std::cout << std::endl;
        }
        std::cout << badCharArr[i] << "\t"; 
    }
    std::cout << std::endl;

}

/*****************************************************************
* @brief: get_suffix
* @param: 
*	suffix[i]=m就是求pattern中以i位置字符为后缀和以最后一个字符为后缀的公共后缀串的长度m
* @retrun:  retrun
* @comment:  -
*****************************************************************/
void get_suffix(const std::string& patt, int* suffix){
    int patt_len = patt.size();
    int i = 0;

    for(i = patt_len-1; i >= 0; --i){
        int j = i;
        while(j>=0 && patt[j] == patt[patt_len-1-(i-j)]){
            --j;
        }
        suffix[i] = i - j;
    }
    for(int i=0; i < patt.size(); ++i){
        std::cout << suffix[i] << "\t";
    }
    std::cout << std::endl;
}

/*****************************************************************
* @brief: buildGoodSuffix, 计算好后缀数组
* good_suffix[i] = x表示下标为i的子串按照好后缀原则需要向后移动x位
* @param: 
*	good_suffix: 好后缀数组, 下标为该位置patt与text发生失配,其值为此时应该右移的位数
* @retrun:  retrun
* @comment:  -
*****************************************************************/
void buildGoodSuffix(const std::string& patt, int* good_suffix){
    int len = int(patt.size());
    int* suffix = new int[len];
    get_suffix(patt, suffix);


    //如果完全不存在和好后缀匹配的子串，则右移整个模式串。
    for (int i = 0; i < len; ++i) {
        good_suffix[i] = len; 
    }

    int j = 0;
    //如果存在一个前缀与好后缀匹配,则右移len-1-i
    for (int i = len-1; i >= 0; --i) {
        //因为下标从0开始,所以这里是i+1和suffix[i]比较]
        //这个判断保证此时存在与好后缀相匹配的子串一定是前缀
        if(i + 1 == suffix[i]){
            //此时0<=j<=len-1-suffix[i]之间的good_suffix都应该移动len-1-i位
            //这里i表示的是匹配的前缀的最后一个字符的下标
            //j表示在这里发生了与文本串失配的情况
            for (; j < len-1-i; ++j) {
                if(good_suffix[j] == len){
                    good_suffix[j] = len - 1 - i; 
                }
            }
        }
    }

    //存在一个子串与发生失配处之后的后缀相匹配
    for (int i = 0; i < len-1; ++i) {
        good_suffix[len-1-suffix[i]] = len - 1 - i;
    }

    for (int i = 0; i < len; ++i) {
        std::cout << good_suffix[i] << "\t";
    }
    std::cout << std::endl;


    delete[] suffix;
    suffix = nullptr;
}


int BoyerMoore(const std::string& pattern, const std::string& text) {
    int i, j;
    int patt_len = int(pattern.size());
    int text_len = int(text.size());

    int* badCharArr = new int[256];
    int* good_suffix = new int[pattern.size()];
    // Preprocessing
    buildBadCharArr(pattern, badCharArr);
    buildGoodSuffix(pattern, good_suffix);

    // Searching
    j = 0;
    while(j <= text_len - patt_len)
    {
        for(i = patt_len - 1; i >= 0 && pattern[i] == text[i + j]; i--);

        if(i < 0)
        {
            /* std::cout << "Found it, pos=" << j << std::endl; */
            /* j += good_suffix[0]; */
            delete[] badCharArr;
            badCharArr = nullptr;
            delete[] good_suffix;
            good_suffix = nullptr;
            return j;
        }
        else
        {
            j += MAX(int(badCharArr[int(text[i + j])]) - (patt_len - 1 - i), good_suffix[i]);
        }
    }

    delete[] badCharArr;
    badCharArr = nullptr;
    delete[] good_suffix;
    good_suffix = nullptr;

    return -1;
}
