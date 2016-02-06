
#include <string.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  using namespace std;

  auto str = "almafa kortefa";
  cout << "Method 1 (strlen): " << strlen(str) << std::endl;
  cout << "Method 2 (char_traits::length): " << std::char_traits<char>::length(str) << std::endl;
  cout << "Method 3 (sizeof): " << sizeof(str) << std::endl; // hoppa! kovetkezo ora anyaga!

  int l = 0;
  // while ciklus
  while(str[l] != 0)
  {
    l++;
  }

  cout << "Method 4 (while != 0): " << l << std::endl;

  return 0;
}
