#include <iostream>
#include <list>
using namespace std;



int main()
{
  list<int> k = {1,2,3,4};

  for(auto e:k){                    /////////////// auto& e
  e = 6;
}
  for(auto e:k){
  cout << e << endl;
}

  return 0;
}
/////////////////////////
1
2
3
4
  改为auto& e之后
6
6
6
6
