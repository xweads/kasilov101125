#include <iostream>
#include <fstream>
#include "intmatrix.hpp"

bool processCommand(IntMatrix &matrix, int command, int param1, int param2)
{
  if (command == 1)
  {
    matrix.insertRowAfter(param1, param2);
    return true;
  }
  
  if (command == 3)
  {
    matrix.insertRowAndColumn(param1, param2);
    return true;
  }
  
  return false;
}

int main(int argc, const char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: invalid number of arguments" << "\n";
    return 1;
  }

  IntMatrix arr;
  std::ifstream in(argv[1]);

  if(!in.is_open())
  {
    std::cerr << "Error: cannot open file" << "\n";
    return 1;
  }

  try
  {
    arr.readFromFile(in);
  }
  catch(const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch(const std::bad_alloc &)
  {
    std::cerr << "Error: memory allocation failed" << "\n";
    return 2;
  }

  std::cout << "Initial matrix:" << std::endl;
  arr.printMatrix();
  std::cout << std::endl;
  
  return 0;
}
