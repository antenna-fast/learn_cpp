// Author: Yaohua Liu
// date: 2024-08-30

#include <iostream>
#include "b.h"

using namespace std;

int main(int argc, char** argv) 
{
  if(argc != 1)
  {
    std::cout << " argc not match, Usage: " << std::endl;
    return -1;
  }

  std::cout << "running: " << argv[0] << std::endl;
  
  B b;

  b.set_b(123);

  std::cout << b.get_b() << std::endl;
  
  return 0;
}