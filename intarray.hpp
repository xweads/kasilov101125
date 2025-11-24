#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include <cstdlib>

struct IntArray
{
  int *data;
  size_t size;

  IntArray(size_t k, int i);
  ~IntArray();
};

#endif
