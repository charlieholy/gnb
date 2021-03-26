#include <iostream>
using namespace std;

namespace testEnvironments{
namespace l2lo{
namespace testcases{
namespace ft527{
namespace SCellActivationWith8CC{
class ft527_SCellActivationWith8CC{};
}
}
}
}
};

using TestcaseToRun = testEnvironments::l2lo::testcases::ft527::SCellActivationWith8CC::ft527_SCellActivationWith8CC;

#include <cxxabi.h>

std::string CxxDemangle(const char* name)
{
 char buffer[1024] = {0};
 size_t size = sizeof(buffer);
 int status;
 if (abi::__cxa_demangle(name, buffer, &size, &status))
 return std::string(buffer, size);
 else
 return name;
}


int main()
{
  //using TestcaseToRun = testEnvironments::l2lo::testcases::ft527::SCellActivationWith8CC::ft527_SCellActivationWith8CC;
  cout << typeid(TestcaseToRun).name() << endl;
  cout << CxxDemangle(typeid(TestcaseToRun).name()) << endl;
}
