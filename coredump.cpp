#include <iostream>
#include <stdio.h>
using namespace std;

class A{};
int g1;
void foo1(){};
static void foo2(){};
static int s1;
static int s2 = 2;
static int s3;
int g2 = 2;
int g3;
const int cg1 = 1;
const static int cs1 = 1;
int main()
{
  printf("g1 %p\n",&g1);
  printf("g2 %p static \n",&g2);
  printf("g3 %p\n",&g3);
  printf("s1 %p\n",&s1);
  printf("s2 %p static \n",&s2);
  printf("s3 %p\n",&s3);
  printf("cg %p\n",&cg1);
  printf("cs %p\n",&cs1);
  A a1;
  A a2;
  printf("stack a1 %p\n",&a1);
  printf("stack a2 %p\n",&a2);
  printf("foo1 %p\n",foo1);
  printf("foo2 %p\n",foo2);
  printf("main %p\n",main);
  A* p1 = new A;
  A* p2 = new A;
  printf("new p1 %p\n",p1);
  printf("new p2 %p\n",p2);
  return 0;
}
