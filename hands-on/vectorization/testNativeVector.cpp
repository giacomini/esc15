#include "nativeVector.h"


int main() {


  using namespace nativeVector;

  std::cout << "native vector size is " << VSIZE << ' ' << sizeof(FVect)/sizeof(float) << std::endl;

  FVect z{0.f};
  
  std::cout << "zero " << z << std::endl; 


  FVect one = z+1.f;
  
  std::cout << "one " << one << std::endl; 

  IVect iz={0};

  IVect io = iz+1;

  std::cout << io <<  ' ' << iz << std::endl;

  std::cout << convert(io) << ' ' << convert(one) << std::endl;
  
  return 0;
};
