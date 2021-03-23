#include <iostream>
#include <array>
#include <chrono>
#include <assert.h>

using namespace std;
int main()
{
  try{
  array<int,24> ar;
  for(int i=0;i<27;i++)
   //cout << i << endl;
    ar.at(i) = i;
  }catch(exception &e){
   cout << "ex: " << e.what() << endl;
  }
  cout << "end........" << endl;

  return 0;
}
//////////////////////////////////////////////////////////////
ex: array::at: __n (which is 24) >= _Nm (which is 24)
end........
