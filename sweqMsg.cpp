#include <iostream>
#include <vector>
#include <array>
using namespace std;

class A{
public:
string s = "123";
int a = 78;
};


int main()
{
  char buf[100] = {0};  //不初始化为0 就会打印一堆乱码
  //A* pa = static_cast<A*>((void*)buf);  //static_cast 需要先将buf转为void*
  A* pa = reinterpret_cast<A*>(buf);  //效果与static_cast 一致

  cout << "main..." << endl;
  cout << "main... s:" << pa->s << endl;
  cout << "main... a:" << pa->a << endl;
}

//////////////////////
main...
main... s:
main... a:0
main... s:
