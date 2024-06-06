// 一个简单的程序，可以计算数字的平方根
#include <cmath>
#include <iostream>
#include <string>

#include "config.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif // USE_MYMATH

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Test_VERSION_MAJOR << "."
              << Test_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]); //c++11

  // calculate square root
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
  std::cout << "use mysqrt" << std::endl;
#else
  const double outputValue = std::sqrt(inputValue);
  std::cout << "use std::sqrt" << std::endl;
#endif
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
