
#include <iostream>


//#define FAHRENHEIT_TO_CELSIUS(f) 5 * (f - 32) / 9
#define FAHRENHEIT_TO_CELSIUS(f) ((5/9.0) * ( (f) - 32))

int main(int argc, char* argv[])
{
  using namespace std;

  cout << FAHRENHEIT_TO_CELSIUS(30) << endl;

  return 0;
}
