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

IntArray::IntArray(const IntArray &rhs):
  data(new int[rhs.getSize()]),
  size(rhs.getSize())
{
  for (size_t i = 0; i < rhs.getSize(); ++i)
  {
    data[i] = rhs.getValue(i);
  }
}

IntArray &IntArray::operator = (const IntArray &rhs)
{
  if (this != &rhs)
  {
    delete[] data;
    size = rhs.getSize();
    int *temp = new int[rhs.getSize()];
    for(size_t i = 0; i < rhs.getSize(); ++i)
    {
      temp[i] = rhs.getValue(i);
    }
    data = temp;
  }
  return *this;
}

IntArray::IntArray(IntArray &&rhs):
  data(rhs.data),
  size(rhs.size)
{
  rhs.data = nullptr;
  rhs.size = 0;
}

IntArray &IntArray::operator = (IntArray &&rhs)
{
  if (this != &rhs)
  {
    delete[] data;
    data = rhs.data;
    size = rhs.size;
    rhs.data = nullptr;
    rhs.size = 0;
  }
  return *this;
}

void IntArray::pushBack(int i)
{
  int *temp = new int[getSize() + 1];
  for (size_t j = 0; j < getSize(); ++j)
  {
    temp[j] = getValue(j);
  }
  temp[getSize()] = i;
  delete[] data;
  data = temp;
  ++size;
}
