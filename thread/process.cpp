/*************************************************************************
  > File Name   : process.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年06月09日 星期二 18时36分47秒
 ************************************************************************/
#include<iostream>
#include <unistd.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstring>
#include <sys/wait.h>

using namespace std;


int main(int argc, char *argv[])
{
    ofstream f;
    f.open("test2.txt", ios::out | ios::trunc);
    pid_t pid;
    int i = 6;
    cout << "before fork" << endl;
    TELL_WAIT();
    if((pid = fork()) < 0){
        cout << "error" << endl;
    }else if(pid == 0){
        //son
        WAIT_PARENT();
        int total;
        cout << "I'am son" << endl;
        /* char buf[100] = ""; */
        /* f << "hello world" << endl; */
    }else{
        cout << "I'am father" << endl;
        TELL_CHILD(pid);
    }

    /* if(waitpid(pid, nullptr, 0) == pid){ */
    /*     // parent */
    /*     cout << "I'am father=" << pid << endl; */
    /*     /1* std::this_thread::sleep_for(chrono::seconds(2)); *1/ */
    /*     cout << "father awake!" << endl; */

    /*     char buf[100] = ""; */
    /*     f << "hahahahahahaha" << endl; */
    /* } */


    f.close();
    cout << "pid=" << getpid() <<  "end" << endl;
    

    return 0;
}
