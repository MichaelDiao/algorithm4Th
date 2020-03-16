#include<iostream>
#include<memory>

using namespace std;

class Person
{
public:
    Person (int v):value(v){
        cout << "Cons" << value << endl;
    }
    virtual ~Person (){
        cout << "~Person" << value << endl;
    }
    
    void show_value() const{
        cout << "my value: " << value << endl;
    }

    int value;

private:
    /* data */
};


int main(int argc, char *argv[])
{
    
    shared_ptr<Person> p1(new Person(1));
    p1->show_value();
    cout << "p1: " << p1.use_count() << ", " << hex << p1.get() << endl;
    shared_ptr<Person> p2 = make_shared<Person>(3);
    p2->show_value();
    cout << "p2: " << p2.use_count() << ", " << hex << p2.get() << endl;

    p1.reset(new Person(4));
    cout << "reset p1: " << p1.use_count() << ", " << hex << p1.get() << endl;
    p1->show_value();


    shared_ptr<Person> p3 = p1;
    p3->show_value();
    cout << "p3: " << p3.use_count() << hex << p3.get() << endl;
    cout << "after p3, p1: " << p1.use_count() << ", " << hex << p1.get() << endl;

    p1.reset();
    cout << "p1 rest: count is " << p1.use_count() << ", pointer is " << hex << p1.get() << endl;
    p3.reset();
    cout << "p3 rest: count is " << p3.use_count() << ", pointer is " << hex << p3.get() << endl;

    cout << "------------------------" << endl;

    int* p4 = new int;
    shared_ptr<int> sp1(p4);
    shared_ptr<int> sp2(p4);

    cout << "sp1: " << sp1.use_count() << ", " << hex << sp1.get() << endl;
    cout << "sp2: " << sp2.use_count() << ", " << hex << sp2.get() << endl;


    cout << "------------------------" << endl;
    weak_ptr<Person> wp(p2);
    cout << "p2: " << p2.use_count() << ", " << hex << p2.get() << endl;
    weak_ptr<Person> wp2(wp);
    cout << "p2: " << p2.use_count() << ", " << hex << p2.get() << endl;

    shared_ptr<Person> wp_tmp(wp.lock()==nullptr? nullptr : wp.lock());
    cout << "p2: " << p2.use_count() << ", " << hex << p2.get() << endl;
    cout << "wp_tmp: " << wp_tmp.use_count() << ", " << hex << wp_tmp.get() << endl;
    wp_tmp->show_value();
    wp_tmp.reset();
    if(wp2.expired())
        cout << "true" << endl;
    else
        cout << "false" << endl;


    return 0;
}
