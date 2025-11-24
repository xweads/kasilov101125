#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include <cstdlib>

struct IntArray
{
  int *data;
  size_t size;

  IntArray(size_t k, int i);
  ~IntArray();
    
  int getValue(size_t id) const noexcept;
  void setValue(size_t id, int v);
  size_t getSize() const noexcept;
  int getLast() const noexcept;
    
  IntArray(const IntArray &rhs);
  IntArray &operator = (const IntArray &rhs);
  IntArray(IntArray &&rhs);
  IntArray &operator = (IntArray &&rhs);
  void pushBack(int i);
};


#endif
