#include<iostream>
#include <algorithm>
#include "BM.h"

using namespace std;


int main(int argc, char *argv[])
{
    string text = "aaaaaaccdx";
    string patt = "aaac";

    while(1){

        cout << "input text: ";
        std::cin >> text;
        cout << "input patt: ";
        std::cin >> patt;
        if(text == "0")
            break;

        cout << BoyerMoore(patt, text) << endl;
    }
    /* int* good_suffix = new int[patt.size()]; */
    /* // Preprocessing */
    /* buildGoodSuffix(patt, good_suffix); */

    /* int* badCharArr = new int[256]; */
    /* int* suffix = new int[patt.size()]; */
    /* buildBadCharArr(patt, badCharArr); */
    /* get_suffix(patt, suffix); */
    
    /* for(int i=0; i < patt.size(); ++i){ */
    /*     cout << suffix[i] << "\t"; */
    /* } */
    /* cout << endl; */
    /* /1* for_each(badCharArr, badCharArr+256, [](int x){ *1/ */
    /* /1*         static int cnt = 0; *1/ */ 
    /* /1*         cout << cnt << ":" << x << ",  "; *1/ */
    /* /1*         ++cnt; *1/ */
    /* /1*         if(cnt != 0 && cnt % 10 == 0){ *1/ */
    /* /1*             cout << endl; *1/ */
    /* /1*         } }); *1/ */
    

    /* delete[] badCharArr; */
    /* badCharArr = nullptr; */

    /* delete[] good_suffix; */
    /* good_suffix = nullptr; */

    return 0;
}
