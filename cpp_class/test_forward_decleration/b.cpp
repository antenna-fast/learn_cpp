#include "b.h"


void B::set_b(int val)
{
  a->set_a(val);

  return;
}

int B::get_b()
{
  return a->get_a();
}
