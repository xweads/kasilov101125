#include "intarray.hpp"

IntArray::~IntArray()
{
  delete[] data;
}

IntArray::IntArray(size_t k, int i):
  data(new int[k]),
  size(k)
{
  for (size_t j = 0; j < k; ++j)
  {
    data[j] = i;
  }
}
