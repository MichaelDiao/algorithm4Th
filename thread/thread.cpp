/*************************************************************************
  > File Name   : thread.cpp
  > Desc      : 
  > Author      : MorganDiao
  > Mail        : morgandiao@163.com
  > Created Time: 2020年06月02日 星期二 11时39分02秒
 ************************************************************************/
#include <vector>
#include<iostream>
#include <thread>
#include <unistd.h>
#include <list>
#include <mutex>

using namespace std;

void MyPrint(int a){
    cout << "I'am thread. a=  " << a << "!" << endl;
    std::thread::id threadid = std::this_thread::get_id();
    cout << "a=" << a << ", thread id=" << threadid << endl;
}

class A
{
public:
    void ReciveCommand(){
        for(int i = 0; i < 100000; ++i){
            cout << "receive a command: " << i << endl;
            mymutex.lock();
            msgQueue.push_back(i);
            mymutex.unlock();
        }
        cout << "================recive command end" << endl;
    }

    bool outMsgLULProc(int &command){
        mymutex.lock();
        if(!msgQueue.empty()){
            command = msgQueue.front();
            msgQueue.pop_front();
            mymutex.unlock();
            return true;
        }
        mymutex.unlock();
        return false;
    }

    void ReadCommand(){
        for(int i = 0; i < 100000; ++i){
            int command = -1;
            bool res = outMsgLULProc(command);
            if(res){
                cout << "del a command = " << command << endl;
            }else{
                cout << "queue is empty! " << i << endl;
            }
        }
        cout << "---------------read command end" << endl;
    }

private:

    list<int> msgQueue;
    mutex mymutex;
};

int main(int argc, char *argv[])
{
    cout << "hello world" << endl;

    A job;
    thread receive_job(&A::ReciveCommand, &job);
    thread read_job(&A::ReadCommand, &job);

    receive_job.join();
    read_job.join();

    cout << "it is end" << endl;

    return 0;
}
