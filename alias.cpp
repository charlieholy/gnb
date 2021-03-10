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
  void run(){
        printf("this %p\n",this);
        auto aa = this;
        printf("*this %p\n",*this);
        cout << typeid(aa).name() << endl;
        //foo(static_cast<A&>(this));

  }
  static void f1(){ cout << "f1 " << endl;}
  int mm = 2;
};

void f2(B& b)
{
  b.mm = 3;
  printf("f2 &b %p\n",b);
}


int main()
{
   B b;
   b.run();b.f1;
   printf("b %p \n",&b);
   f2(b);
   printf("b.mm %d\n",b.mm);


   B* b1 = new B;
   B& b2 = *b1;
   B& b3 = *b1;
   B& b4 = b2;

   B& b5 = b;

cout << "b: " << typeid(b).name() << endl;
cout << "b1: " << typeid(b1).name() << endl;
cout << "b2: " << typeid(b2).name() << endl;
cout << "b3: " << typeid(b3).name() << endl;
cout << "b4: " << typeid(b4).name() << endl;

cout << "b1 %p" << &b1 << endl;
cout << "b2 %p" << &b2 << endl;
cout << "b3 %p" << &b3 << endl;
cout << "b4 %p" << &b4 << endl;

cout << "b %p" << &b << endl;
cout << "b5 %p" << &b5 << endl;



   return 0;
}
/////////////////////////
this 0x7fff1cc07c90
*this 0x7fff1cc07c40
~B
~A
P1B
b 0x7fff1cc07c90
f2 &b 0x7fff1cc07c50
~B
~A
b.mm 3
b: 1B
b1: P1B
b2: 1B
b3: 1B
b4: 1B
b1 %p0x7fff1cc07c88
b2 %p0x1157c20
b3 %p0x1157c20
b4 %p0x1157c20
b %p0x7fff1cc07c90
b5 %p0x7fff1cc07c90
~B
~A
