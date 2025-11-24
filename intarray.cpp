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

int IntArray::getValue(size_t id) const noexcept
{
  if (id < size) {
    return data[id];
  }
  return 0;
}

void IntArray::setValue(size_t id, int v)
{
  if (id < size) {
    data[id] = v;
  }
}

size_t IntArray::getSize() const noexcept
{
  return size;
}

int IntArray::getLast() const noexcept
{
  if (size > 0) {
    return getValue(size - 1);
  }
  return 0;
}
