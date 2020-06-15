/*************************************************************************
  > File Name   : file_test.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年06月09日 星期二 17时47分07秒
 ************************************************************************/
#include<iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    ifstream f_r;
    f_r.open("test.txt", ios::in | ios::app);

    char data[100] = "";

    cout << "data=" << endl;
    f_r >> data;
    cout << data << endl;

    f_r.close();
    cout << "end!" << endl;


    cout << "write test: " << endl;
    ofstream out_f;
    out_f.open("out_file.txt", ios::out | ios::trunc);
    for(int i=9; i<20; ++i){
        out_f << i << "\n";
    }

    out_f.close();
    

    return 0;
}
