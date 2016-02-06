
#include <iostream>


inline double fahrenheit_to_celsius(double fahrenheit)
{
	return 5 * (fahrenheit - 32) / 9;
}

int main(int argc, char* argv[])
{
  using namespace std;

  cout << fahrenheit_to_celsius(30) << endl;

  return 0;
}
