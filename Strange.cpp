#include <iostream>
#include <array>
#include <chrono>
#include <assert.h>
using namespace std;

class A{
public:
void foo() && {}     //这里限制必须用右值来调用该方法
};

//void foo(A&& a) && {}

int main()
{
  A a;
  std::move(a).foo();
  cout << "asd" << endl;
  return 0;
}
