#include <iostream>
using namespace std;
#include <stdio.h>

class A{
public:
        virtual ~A(){ cout << "~A" << endl;}
};
static void foo(A& a){};
class B : public A
{
public:
  ~B(){cout << "~B" << endl;}
  void run(){foo(*this);}

};



int main()
{
  {
        A* a = new B;
        delete(a);
  }
{
   B();
}
        return 0;
}
///////////////////
~B
~A
~B
~A
///////////////////
如果A的析构不加virtual方法  那么该基类指针指向子类的时候 在他析构的时候不会析构子类。。。造成内存泄露
