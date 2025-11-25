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

  int command = 0;
  int param1 = 0;
  int param2 = 0;
    
  arr.printMatrix();
  std::cout << std::endl;
  
  while (std::cin >> command >> param1 >> param2)
  {
    bool commandProcessed = false;
    try
   {
     commandProcessed = processCommand(arr, command, param1, param2);
   }
     catch (const std::logic_error &e)
   {
     std::cerr << e.what() << "\n";
     return 3;
   }
     catch (const std::bad_alloc&)
   {
     std::cerr << "Error: memory allocation failed" << "\n";
     return 2;
   }

   if (!commandProcessed)
   {
     std::cerr << "Error: unknown command" << "\n";
     return 3;
   }

   std::cout << "After command " << command << " " << param1 << " " << param2 << ":" << std::endl;
   arr.printMatrix();
   std::cout << std::endl;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: invalid input parameters" << "\n";
    return 3;
  }

  return 0;
};
