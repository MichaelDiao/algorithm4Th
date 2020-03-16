#include<iostream>

using namespace std;

class Base{
    public:
        Base(int data=1):b(data){
            cout << "base()" << endl;
        }
        ~Base(){
            cout << "~base()" << endl;
        }

        virtual void test1(){
            cout << "Base::test1()" << endl;
        }
        virtual void test2(){
            cout << "Base::test2()" << endl;
        }

        virtual void test3(){
            cout << "Base::test3()" << endl;
        }

        int b;
};


class Derive: public Base{
    public:
        Derive(int data=2):d(data){
            cout << "Derive()" << endl;
        }

        ~Derive(){
            cout << "~Derive()" << endl;
        }

        virtual void test1(){
            cout << "Derive::test1()" << endl;
        }

        virtual void test2(){
            cout << "Derive::test2()" << endl;
        }


        int d;
};


typedef void(*VTable)();//定义函数指针
void PrintBase(Base &b)
{
    VTable vtb = (VTable)(*((unsigned long *)*(unsigned long *)&b));
    //vtb就是函数的地址
    int i = 0;
    cout << "Vtable is " << vtb << endl;
    while (i < 3)
    {
        cout << "NUM " << i+1 << "Function " << *(((unsigned long*)(*(unsigned long *)&b)) + i) << endl;
        cout << "------->";
        vtb();
        vtb = (VTable)*(((unsigned long*)(*(unsigned long *)&b)) + i);
        ++i;
        //向后偏移8字节
    }
    cout << "End" << endl;
}
void PrintDerive(Derive &b)
{
    VTable vtb = (VTable)(*((unsigned long *)*(unsigned long *)&b));
    //vtb就是函数的地址
    int i = 0;
    cout << "Vtable is " << vtb << endl;
    while (i < 3)
    {
        cout << "NUM " << i + 1 << "Function " << *(((unsigned long*)(*(unsigned long *)&b)) + i) << endl;
        cout << "------->";
        vtb();
        vtb = (VTable)*(((unsigned long*)(*(unsigned long *)&b)) + i);
        ++i;
        //向后偏移8个字节
    }
    cout << "End" << endl;
}

int main(int argc, char *argv[])
{
    Base b;
    Derive d;
    cout << "size Base:" << sizeof(Base) << endl;
    cout << "size Base b:" << sizeof(b) << endl;
    cout << "size Derive:" << sizeof(Derive) << endl;
    cout << "size Derive d:" << sizeof(d) << endl;
    cout << "size int* :" << sizeof(int*) << endl;
    PrintBase(b);
    PrintDerive(d);

    return 0;
}
