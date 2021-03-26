Defined in header <type_traits>
template< bool B, class T, class F >
struct conditional;
(since C++11)
Provides member typedef type, which is defined as T if B is true at compile time, or as F if B is false.

The behavior of a program that adds specializations for conditional is undefined.

Member types
Member type	Definition
type	T if B == true, F if B == false
Helper types
template< bool B, class T, class F >
using conditional_t = typename conditional<B,T,F>::type;
(since C++14)
Possible implementation
template<bool B, class T, class F>
struct conditional { typedef T type; };
 
template<class T, class F>
struct conditional<false, T, F> { typedef F type; };
Example
Run this code
#include <iostream>
#include <type_traits>
#include <typeinfo>
 
int main() 
{
    typedef std::conditional<true, int, double>::type Type1;
    typedef std::conditional<false, int, double>::type Type2;
    typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
 
    std::cout << typeid(Type1).name() << '\n';
    std::cout << typeid(Type2).name() << '\n';
    std::cout << typeid(Type3).name() << '\n';
}
Possible output:

int
double
double
