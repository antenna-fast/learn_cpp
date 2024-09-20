#include "a.h"


void A::set_a(int val)
{
  std::cout << "calling set a" << std::endl;
  a = val;
}

int A::get_a()
{
  return a;
}
