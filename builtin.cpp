#include <iostream>
using namespace std;
int main()
{

  cout << "0x78c: " << __builtin_ffs(0x78c) << endl;
  return 0;
}


int __builtin_ffs (unsigned int x)
返回x的最后一位1的是从后向前第几位，比如7368（1110011001000）返回4。
int __builtin_clz (unsigned int x)
返回前导的0的个数。
int __builtin_ctz (unsigned int x)
返回后面的0个个数，和__builtin_clz相对。
int __builtin_popcount (unsigned int x)
返回二进制表示中1的个数。
int __builtin_parity (unsigned int x)
返回x的奇偶校验位，也就是x的1的个数模2的结果。
   此外，这些函数都有相应的usigned long和usigned long long版本，只需要在函数名后面加上l或ll就可以了，比如int __builtin_clzll。

   上述函数，均不需要添加头文件，因为它们是GCC的内置函数，为汇编实现，因此只需要用GCC进行编译即可！



   速率测试：测试__builtin_parity函数，计算2^28次运算。

   方法一：利用维基上的快速汉明重量计算，然后模2，时间1.23秒

   方法二：利用__builtin_parity函数，时间0.26秒，速度提升4倍多

    但 __builtin_popcount计算1的个数时间为1.55秒，而快速汉明重量计算仅需要1.21秒。
