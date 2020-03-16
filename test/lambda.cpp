#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    auto f = []{return 43;};

    cout << "f is: " << f() << endl;


    int i = 12;
    auto f2 = [i]{return i+5;};
    cout << "f2 is: " << f2() << endl;



    return 0;
}
