#include<iostream>
#include<string>

using namespace std;

class Base{
public:
    Base()
        :m_value(NULL){
        cout << "base constructor" << endl;
    }
    virtual ~Base(){
        delete m_value;
        m_value = NULL;
        cout << "base destructor" << endl;
    }

    void set_value(const int value){
        if(!m_value){
            m_value = new int(value);
        }else{
            *m_value = value;
        }
    }

private:
    int *m_value;
};

class subClass: public Base{
public:
    subClass():Base(), m_name(NULL){
        cout << "subclass constructor" << endl;
    }
    ~subClass(){
        delete m_name;
        m_name = NULL;
        cout << "subclass destructor" << endl;
    }
    void set_name(const string &name){
        if(!m_name){
            m_name = new string(name);
        }else{
            *m_name = name;
        }
    }
private:
    string *m_name;

};


int main(int argc, char *argv[])
{
    Base *b = new subClass();
    b->set_value(20);
    ((subClass*)b)->set_name("Linda");
    delete b;
    b = NULL;
    
    return 0;
}
