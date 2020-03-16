#include<iostream>

using namespace std;

class B{
    public:
        B(){
            cout <<"it is B" <<endl;
        }
        ~B(){
            cout << "bye B" <<endl;
        }
    private:
        int b;
};


class C1: public B{
    public:
        C1(){
            cout <<"it is C1" <<endl;
        }
        ~C1(){
            cout << "bye C1" <<endl;
        }
    private:
        int c1;
};


class C2: public B{
    public:
        C2(){
            cout <<"it is C2" <<endl;
        }
        ~C2(){
            cout << "bye C2" <<endl;
        }
    private:
        int c2;
};


class D: public C2, public C1{
    public:
        D(){
            cout <<"it is D" <<endl;
        }
        ~D(){
            cout << "bye D" <<endl;
        }
    private:
        int d;
};



int main(int argc, char *argv[])
{
    cout << "start" <<endl;
    cout << "B: " << sizeof(B) << endl;
    cout << "C1: " << sizeof(C1) << endl;
    cout << "C2: " << sizeof(C2) << endl;
    cout << "D: " << sizeof(D) << endl;

    B b;
    cout << "--------" << endl;
    C1 c1;
    cout << "--------" << endl;
    C2 c2;
    cout << "--------" << endl;
    D d;
    
    return 0;
}
