#ifndef INTMATRIX_HPP
#define INTMATRIX_HPP

#include "intarray.hpp"
#include <iostream>

struct IntMatrix
{
  IntArray matrix = IntArray(0, 0);
  size_t rows = 0;
  size_t cols = 0;

  std::istream &readFromFile(std::istream &in);
  void printMatrix() const noexcept;
};

#endif
