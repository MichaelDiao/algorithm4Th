#include <string>
#include <iostream>
#include "kmp.h"

//基于next公式的next求解
//不足：对重复串仍存在多余的比较
void get_next(std::string T, int *next){
    size_t len = T.size();
    next[1] = 0;
    size_t j = 1;
    size_t cur_len = 0;//当前公共前后缀的长度

    while( j < len){
        if(cur_len == 0 || T[cur_len] == T[j]){//匹配时, j应该向后移动，当前公共前后缀的长度也应该加1
            ++j;
            ++cur_len;
            next[j] = cur_len;
        }else{
            cur_len = next[cur_len];
        }
    }

}   
//对原始kmp算法改进,解决存在重复串的无意义比较
void get_next_improved(std::string T, int *next){
    size_t len = T.size();
    next[1] = 0;
    size_t j = 1;
    size_t cur_len = 0;//当前公共前后缀的长度

    while( j < len){
        if(cur_len == 0 || T[cur_len] == T[j]){//匹配时, j应该向后移动，当前公共前后缀的长度也应该加1
            ++j;
            ++cur_len;
            if(T[cur_len] != T[j]){
                next[j] = cur_len;
            }else{//这里表示T[cur_len] == T[j] == T[cur_len_old] == T[j_old]
                //而cur_len == j_old, 也就是下标为cur_len_old, j_old以及j三个位置的字符相等
                //因此这时可以直接用j_old位置的next值，这样可以减少匹配次数
                next[j] = next[cur_len];
            }
        }else{
            cur_len = next[cur_len];
        }
    }

}   

//原始kmp算法，按照求解公共前后缀思想去做的
//存在不足：当模式串中存在大量重复字符时，仍会多一些无谓的比较， 如patt=aaaaax, text=aaaabcde
void get_prefix(std::string T, int * prefix){
    //prefix[pos]=value的含义是：
    //T[i], i为[0,pos], 的子串的公共前后缀长度为value
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < int(T.size())){
        //T[i]表示后缀，T[len]表示前缀，相等时，公共前后缀长度应该+1, 然后i后移
        if(T[i] == T[len]){
            ++len;
            prefix[i] = len;
            ++i;
        }else{
            //如果不相等，且len>0(表示非prefix的0的位置)， 则应该记录当前位置之前的子串的公共前后缀长度
            if(len > 0){
                len = prefix[len-1];
            }else{
                prefix[i] = 0;
                ++i;
            }
        }
    }

}

/*****************************************************************
* @brief: kmp算法
* @param: 
*	pos: 表示开始搜索的位置，默认为0
* @retrun:  返回匹配的模式串的首字母的位置，如果不存在则返回-1
* @comment:  -
*****************************************************************/
int KMP_search_base_prefix(std::string text, std::string pattern, int pos){
    size_t text_index = pos;
    size_t pattern_index = 0;
    int* prefix = new int[pattern.size()];
    std::cout << "size:" << pattern.size() << std::endl;
    get_prefix(pattern, prefix);

    for(size_t i = 0; i<pattern.size(); ++i){
        std::cout << prefix[i] << "\t";
    }
    std::cout << std::endl;

    size_t cnt = 0;
    while(text_index < text.size() && pattern_index < pattern.size()){
        ++cnt;
        if(text[text_index] == pattern[pattern_index]){
            ++text_index;
            ++pattern_index;
        }else{
            if(pattern_index == 0){
                ++text_index;
            }else{
                pattern_index = prefix[pattern_index-1];
            }
        }
    }
    std::cout << "compare number: " << cnt << std::endl;

    delete[] prefix;
    prefix = nullptr;
    if(pattern_index >= pattern.size()){
        return text_index-pattern_index;
    }else{
        return -1;
    }
}

/*****************************************************************
* @brief: kmp算法
* @param: 
*	pos: 表示开始搜索的位置，默认为0
* @retrun:  返回匹配的模式串的首字母的位置，如果不存在则返回-1
* @comment:  -
*****************************************************************/
int KMP_search_base_next(std::string text, std::string pattern, int pos){
    size_t text_index = pos;
    size_t pattern_index = 0;
    int* next = new int[pattern.size()];
    std::cout << "size:" << pattern.size() << std::endl;
    /* get_next(pattern, next); */
    get_next_improved(pattern, next);

    for(size_t i = 0; i<pattern.size(); ++i){
        std::cout << next[i] << "\t";
    }
    std::cout << std::endl;

    size_t cnt = 0;
    while(text_index < text.size() && pattern_index < pattern.size()){
        ++cnt;
        if(pattern_index == 0 || text[text_index] == pattern[pattern_index]){
            ++text_index;
            ++pattern_index;
        }else{
            pattern_index = next[pattern_index];
        }
    }

    std::cout << "compare number: " << cnt << std::endl;


    delete[] next;
    next = nullptr;

    if(pattern_index == pattern.size()){//匹配成功
        return text_index - pattern_index;
    }else{
        return -1;
    }
}
