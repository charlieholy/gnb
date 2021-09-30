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


//////////////////

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
   std::ostringstream os;

   float a = 0.3;
   char buf[5] = {1,2,3,4,0};
   //memcpy((char*)buf,(char*)&a,4);
   std::copy_n(buf,4,(char*)&a);
   cout << std::hex << buf << " " << endl;
   return 0;
}

./a.out > 1.txt 
 hexdump -c 1.txt
  
00000000  01 02 03 04 20 0a                                 |.... .|
00000006

/////////////////////////////////////////////
  
  #include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
   std::ostringstream os;

   float img = 0.123;
   float real = 0.456;
   char buf[9]{0};

   std::copy_n((char*)&img,4,buf);
   std::copy_n((char*)&real,4,buf+4);
   std::cout << std::hex << std::setfill('0');
   for(int i=0;i<8;i++)
   {
     std::cout << setw(2) <<  +(static_cast<uint8_t>(buf[i]));
   }
   std::cout << std::endl;
  return 0;
}


6de7fb3dd578e93e

  
  ///////////////////////////////////////////////////
  
import struct;
value = 1.23456
data = struct.pack('f',value)
print(data)
un = struct.unpack('f',data)
print(un)

###

un2 = struct.unpack('ff', bytes.fromhex('6de7fb3dd578e93e'))
print(un2)

#b'\x10\x06\x9e?'
#(1.2345600128173828,)
#(0.12300000339746475, 0.4560000002384186)





