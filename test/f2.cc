#include<iostream>
#include<cstdio>


#define sqar(x) printf("the squart of "#x" is %d.\n", (x)*(x))
#define tt(...) printf(__VA_ARGS__)
#define t2(x, ...) printf(__VA_ARGS__, x)

extern const int count;

int main(){
    std::cout << "count:" << count << std::endl;
    /* count++; */
    /* std::cout << "++count:" << count << std::endl; */
    int a = 2;
    const int &r = a;
    const int &r2 = r + a;

    double dval = 3.14;
    const int &r3 = dval;

    std::cout <<" r:" << r << std::endl;
    std::cout <<" r2:" << r2 << std::endl;
    std::cout <<" r3:" << r3 << std::endl;
    sqar(10);
    tt("tt test %d.\n", a);
    t2(10, "t2 test %d, a=%d.\n", a);

    return 0;
}
