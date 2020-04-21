/*************************************************************************
  > File Name   : BM.h
  > Desc      : BM算法的具体实现
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: Sun Apr 19 21:33:33 2020
 ************************************************************************/

#ifndef _BM_H
#define _BM_H

void buildBadCharArr(const std::string& patt, int* badCharArr);
//suff[i]=m就是求pattern中以i位置字符为后缀和以最后一个字符为后缀的公共后缀串的长度m
void get_suffix(const std::string& patt, int* suffix);

void buildGoodSuffix(const std::string& patt, int* good_suffix);
int BoyerMoore(const std::string& pattern, const std::string& text);

#endif
