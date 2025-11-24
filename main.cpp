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
