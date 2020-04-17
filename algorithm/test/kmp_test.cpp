#include<iostream>
#include "kmp.h"

using namespace std;




int main(int argc, char *argv[])
{
    /* string T = "ABABABCABAABABABAB"; */
    /* string patt = "ABABCABAA"; */
    string T = "aaaabcde";
    string patt = "aaaaax";

    int pos = KMP_search_base_next(T, patt, 0);

    std::cout << "base on next, pattern pos:" << pos << std::endl;

    pos = KMP_search_base_prefix(T, patt, 0);

    std::cout << "base on prefix, pattern pos:" << pos << std::endl;
    

    return 0;
}
