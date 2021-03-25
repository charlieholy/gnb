#include <iostream>
#include <fstream>
#include <array>
#include <chrono>
#include <vector>
#include <assert.h>
using namespace std;

class A{
public:
  void yoo(){
     auto f = [&](){   ///// 
        this->foo();
        cout << "ff.." << endl;
     };
     f();
  }
private:
  void foo(){cout << "foo.." << endl;}
};

int main()
{
  A a;
  a.yoo();
  cout << "asd" << endl;
  return 0;
}

////////////
   1、空。没有使用任何函数对象参数。
   2、=。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是值传递方式（相当于编译器自动为我们按值传递了所有局部变量）。
   3、&。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是引用传递方式（相当于编译器自动为我们按引用传递了所有局部变量）。
   4、this。函数体内可以使用Lambda所在类中的成员变量。
   5、a。将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。要修改传递进来的a的拷贝，可以添加mutable修饰符。
   6、&a。将a按引用进行传递。
   7、a, &b。将a按值进行传递，b按引用进行传递。
   8、=，&a, &b。除a和b按引用进行传递外，其他参数都按值进行传递。
   9、&, a, b。除a和b按值进行传递外，其他参数都按引用进行传递。
