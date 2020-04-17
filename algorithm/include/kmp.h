#ifndef __KMP_H__
#define __KMP_H__

void get_next(std::string T, int *next);
void get_next_improved(std::string T, int *next);

//基于next公式的方式理解的kmp算法
//next[j] = {(0, j=1); (max{k|1<k<j, 'P1,P2,...P(k-1)' == 'P(j-k+1)...P(j-1)'}该集合不为空); (1, 其他情况)}
int KMP_search_base_next(std::string text, std::string pattern, int pos=0);//kmp算法




void get_prefix(std::string T, int * next);
//基于公共前后缀的方式理解的kmp算法
//prefixx中记录的是当前位置之前（包括当前）的子串的公共前后缀的长度len，失配后，当前位置要移动到当前位置之前一位的prefix中记录的len所对应的位置
//由于prefix从0计数，因此len实际表示的是公共前后缀的后一位，可以直接用该位的字符进行比较
int KMP_search_base_prefix(std::string text, std::string pattern, int pos=0);//kmp算法

#endif /* ifndef KMP */
