#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A constructor" << endl;
    }
    virtual ~A(){
        cout << "A destructor" << endl;
    }
    void Work(){
        cout << "A work" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "B constructor" << endl;
    }
    ~B(){
        cout << "B destructor" << endl;
    }
    void Work(){
        cout << "B work" << endl;
    }
};
int main(){
    A* a = new B();
    a->Work();
    delete a;
    // system("pause");
    return 0;
}