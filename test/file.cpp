#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    //out是以内存角度描述的，因此写入磁盘数据，对内存为out, 对文件来说是写文件
    ofstream fout("out.txt");
    fout << "hello" << " " << 200;
    fout.close();

    //in 为内存从磁盘获取数据，对内存来说，是输入，对文件来说是读文件
    ifstream fin("out.txt");
    string s;
    int num;
    fin >> s >> num;
    cout << "s:" << s << ", num: " << num << endl;
    

    return 0;
}
