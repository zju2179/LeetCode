#include <iostream>
#include <cstdio>
using namespace std;
class A {
public:
    virtual void vfunc1();
    virtual void vfunc2();
    void func1();
    void func2();
private:
    int m_data1, m_data2;
};
    
class B : public A {
public:
    virtual void vfunc1();
    void func1();
private:
    int m_data3;
};
    
class C: public B {
public:
    virtual void vfunc2();
    void func2();
private:
    int m_data1, m_data4;
};
int main(){
    int *p = (int*)malloc(sizeof(int));
    *p = 10;
    cout<<"*p = " << *p << endl;
    free(p);

    p = (int*)malloc(sizeof(int));
    *p = 20;
    cout<<"*p = " << *p << endl;
    free(p);

    A* b = new B();
    A* c = new C();
    b->vfunc1();
    b->vfunc2();
    return 0;
}