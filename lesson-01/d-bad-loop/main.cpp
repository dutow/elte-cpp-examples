
#include <iostream>

int main(int argc, char* argv[])
{
  using namespace std;

  int i = 5;

  #pragma warning disable -Wparentheses
  if ( i = 3 )
  {
    std::cout << "i erteke kisebb, mint harom!" << std::endl;
  } else
  {
    int c = 3;
    int n = 1;
    while(c < i)
      c += 3;
      n++;

    std::cout << "i-ben " << n << "-szer van meg harom." << std::endl;
  }

  return 0;
}
