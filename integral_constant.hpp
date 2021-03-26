1 integral_constant类
这个类是所有traits类的基类，分别提供了以下功能：

value_type 表示值的类型
value表示值
type 表示自己, 因此可以用::type::value来获取值
true_type和false_type两个特化类用来表示bool值类型的traits，很多traits类都需要继承它们


// from c++11 standard
namespace std {
  template <class T, T v>
  struct integral_constant {
    static constexpr T value = v;
    typedef T value_type;
    typedef integral_constant<T,v> type;
    constexpr operator value_type() { return value; }
  };
  typedef integral_constant<bool, true> true_type;
  typedef integral_constant<bool, false> false_type;
}

// from boost
template <class T, T val>
struct integral_constant
{
   typedef integral_constant<T, val>  type;
   typedef T                          value_type;
   static const T value = val;
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

下面是调用代码，看看基本使用方法：

#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

int main() {
  typedef std::integral_constant<int, 1> one_t;

  cout << "one_t::value: " << one_t::value << endl;
  cout << "one_t::type::value: " << one_t::type::value << endl;
}
输出结果是：

one_t::value: 1
one_t::type::value: 1
注意value_type()是一个类型转换函数，有了它，可以将模板类转换成T(这里T是int), 调用代码如下：

int i = one_o; // same as int i = 1;
// or int i = static_cast<int>(one_o);
// or one_o.operator one_t::value_type();
