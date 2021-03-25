#include <iostream>
#include <fstream>
#include <array>
#include <chrono>
#include <vector>
#include <assert.h>
using namespace std;

class A{
public:
string s;
int i;
};

int main()
{
  fstream fs;
    fs.open("e.dupm", ios::in | ios::out | ios::binary | ios::trunc);
    if (not fs.is_open())
    {
        return false;
    }
  A a;
  a.s = "ss";
  a.i = 9;
  fs.write((char*)&a,sizeof(a));
#if 0 //double free
  A b;
  fs.seekg(0);
  fs.read((char*)&b,sizeof(b));
  for(int i=0;i<sizeof(b);i++)
{
  cout << hex << (int)(*(char*)(&b+i)) << " " ;
}
cout << endl;
  cout << "b.s: " << b.s << " b.i: " << b.i << endl;
#endif
  char buf[1024];
  fs.seekg(0);
  fs.read((char*)&buf,sizeof(a));
  A* pa = reinterpret_cast<A*>(buf);  //效果与static_cast 一致
  cout << "b.s: " << pa->s << " b.i: " << pa->i << endl;

  fs.close();

  return 0;
}
