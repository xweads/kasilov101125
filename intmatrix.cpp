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

void IntMatrix::insertRowAfter(int after_row, int val)
{
  if (after_row < 0 || static_cast<size_t>(after_row) > rows)
  {
    throw std::logic_error("Error: row index out of range");
  }

  size_t insert_pos = (after_row == 0) ? 0 : static_cast<size_t>(after_row);
  int *temp = new int[(rows + 1) * cols];

  for (size_t i = 0; i < insert_pos; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      temp[i * cols + j] = getElement(i, j);
    }
  }

  for (size_t j = 0; j < cols; ++j)
  {
    temp[insert_pos * cols + j] = val;
  }

  for (size_t i = insert_pos; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      temp[(i + 1) * cols + j] = getElement(i, j);
    }
  }

  delete[] matrix.data;
  matrix.data = temp;
  matrix.size = (rows + 1) * cols;
  ++rows;
}

void IntMatrix::insertRowAndColumn(int after_row, int after_col)
{
  if (after_row < 0 || static_cast<size_t>(after_row) > rows ||
      after_col < 0 || static_cast<size_t>(after_col) > cols)
  {
    throw std::logic_error("Error: row or column index out of range");
  }

  size_t insert_row_pos = (after_row == 0) ? 0 : static_cast<size_t>(after_row);
  size_t insert_col_pos = (after_col == 0) ? 0 : static_cast<size_t>(after_col);
  int *temp = new int[(rows + 1) * (cols + 1)];

  for (size_t i = 0; i < (rows + 1) * (cols + 1); ++i)
  {
    temp[i] = 0;
  }

  for (size_t i = 0; i < rows; ++i)
  {
    size_t new_i = (i < insert_row_pos) ? i : i + 1;
    
    for (size_t j = 0; j < cols; ++j)
    {
      size_t new_j = (j < insert_col_pos) ? j : j + 1;
      temp[new_i * (cols + 1) + new_j] = getElement(i, j);
    }
  }

  delete[] matrix.data;
  matrix.data = temp;
  matrix.size = (rows + 1) * (cols + 1);
  ++rows;
  ++cols;
}
