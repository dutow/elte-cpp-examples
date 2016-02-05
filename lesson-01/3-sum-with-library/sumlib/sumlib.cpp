
#include "sumlib.h"

#include <iostream>

namespace sumlib
{
  int sum_dividible_by_seven(int min, int max)
  {
    int sum = 0;
    for(int i=min; i<=max; ++i)
    {
      if(i % 7 == 0)
      {
        sum += i;
      }
    }

    return sum;
  }

  void print_a_number(int number)
  {
    std::cout << "The number is: " << number << std::endl;
  }
}
