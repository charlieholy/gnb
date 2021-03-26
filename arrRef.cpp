#include <iostream>
#include <stdio.h>
using namespace std;

struct A{};

int main()
{
  char arr[123] = {0,1,2,3};
  char (&b)[123] = arr;
  cout << "asd:" << (int)b[3] << endl;
  cout << "arr:" << hex << (void*)&arr[0] << endl;
  cout << "b:" << hex << (void*)&b[0] << endl;
  printf("&arr[0] %p\n",&arr[0]);
  printf("&b[0] %p\n",&b[0]);
  printf("arr %p\n",arr);
  printf("b %p\n",b);
  printf("&arr %p\n",&arr);
  printf("&b %p\n",&b);
  return 0;
}
//////////////
asd:3
arr:0x7ffdd9fd70c0
b:0x7ffdd9fd70c0
&arr[0] 0x7ffdd9fd70c0
&b[0] 0x7ffdd9fd70c0
arr 0x7ffdd9fd70c0
b 0x7ffdd9fd70c0
&arr 0x7ffdd9fd70c0
&b 0x7ffdd9fd70c0
