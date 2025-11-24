#include "intmatrix.hpp"
#include <fstream>

std::istream &IntMatrix::readFromFile(std::istream &in)
{
  in >> rows >> cols;
  if (!in)
  {
    throw std::logic_error("Error: invalid matrix dimensions");
  }
  
  if (rows == 0 || cols == 0)
  {
    throw std::logic_error("Error: matrix dimensions cannot be zero");
  }

  matrix = IntArray(rows * cols, 0);

  for (size_t ind = 0; ind < matrix.size; ++ind)
  {
    in >> matrix.data[ind];
    if (!in)
    {
      throw std::logic_error("Error: invalid matrix data");
    }
  }
  return in;
}

void IntMatrix::printMatrix() const noexcept
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cout << matrix.data[i * cols + j];
      if (j < cols - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

int IntMatrix::getElement(size_t i, size_t j) const
{
  if (i < rows && j < cols) {
    return matrix.getValue(i * cols + j);
  }
  return 0;
}

void IntMatrix::setElement(size_t i, size_t j, int v)
{
  if (i < rows && j < cols) {
    matrix.setValue(i * cols + j, v);
  }
}
