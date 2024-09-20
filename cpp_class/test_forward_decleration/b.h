#ifndef __B_H__
#define __B_H__

#include "a.h"

class A;

class B
{
  public:
    A* a;

    void set_b(int val);
    int get_b();

};

#endif
