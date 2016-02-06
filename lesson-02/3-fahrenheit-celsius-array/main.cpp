
#include <iostream>


inline double fahrenheit_to_celsius(double fahrenheit)
{
	return 5/9.0 * (fahrenheit - 32);
}

int main(int argc, char* argv[])
{
  using namespace std;

  double inputs[] = { 20.0, 30, 45.2f, -5 };

  cout << "Bemenetek szama: " << sizeof(inputs) / sizeof(double) << endl;

  for(double f: inputs)
  {
    cout << f << " fahrenheit in celsius: " << fahrenheit_to_celsius(f) << endl;
  }

  return 0;
}
