/*************************************************************************
  > File Name   : thread_linux.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年06月10日 星期三 17时24分36秒
 ************************************************************************/
#include<iostream>
#include <pthread.h>
#include <chrono>
#include <unistd.h>
#include <thread>

using namespace std;

pthread_t t1;

void print(const char * str){
    pid_t pid = getpid();
    cout << " son thread id=" << pthread_self() << endl;
    cout << "t1=" << t1 << endl;
    cout << str << endl << "son thread end." << endl;
}

void *thread_main(void *arg){
    print((const char*)arg);
    return ((void*)0);
}


int main(int argc, char *argv[])
{
    cout << "start" << endl;
    char t[100] = "hello world";
    int status = pthread_create(&t1, nullptr, thread_main, t);
    if(status != 0){
        cout << "create pthread error" << endl;
    }

    cout << "t1=" << t1 << ", main thread sleep" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "bye" << endl;
    

    return 0;
}
