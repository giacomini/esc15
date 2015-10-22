#include<iostream>
#include<iomanip>
#include<cmath>
#include<limits>
#include<cstdio>

template<typename T> 
void print(T x) {
 std::cout<< std::hexfloat << x <<' '<<  std::scientific << std::setprecision(8) << x << ' ' <<  std::defaultfloat << x << std::endl;
}

int main () {

  std::cout << std::boolalpha;
  std::cout << "Minimum value: " << std::numeric_limits<float>::min() << '\n';
  std::cout << "Maximum value: " << std::numeric_limits<float>::max() << '\n';
  std::cout << "Is signed: " << std::numeric_limits<float>::is_signed << '\n';
  std::cout << "significant bits: " << std::numeric_limits<float>::digits << '\n';
  std::cout << "has infinity: " << std::numeric_limits<float>::has_infinity << '\n';
  std::cout << "base 10 digits: " << std::numeric_limits<float>::digits10 << '\n';
  std::cout << "epsilon: " << std::numeric_limits<float>::epsilon() << '\n';
  print(std::numeric_limits<float>::epsilon());
  print(0.1f);
  return 0;
}
