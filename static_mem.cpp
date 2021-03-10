#include <iostream>
using namespace std;
#include <stdio.h>
#include <array>
class A{
public:
void foo(){cout << "A" << endl;}
};

class B{
public:
static void foo(){cout << "B" << endl;}
};

int main()
{
  B::foo();
  A().foo();
  return 0;
}
////////////
B
A
