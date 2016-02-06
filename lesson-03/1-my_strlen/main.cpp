
#include <iostream>


unsigned int my_strlen(const char* const str)
{
  const char* ptr = str;
  while(*ptr != 0)
  {
    ptr++;
  }
  return ptr-str;
}

int main(int argc, char* argv[])
{
  using namespace std;

  cout << my_strlen("almafa") << endl;
  cout << my_strlen("barack") << endl;
  cout << my_strlen("banan") << endl;

  char arr[] = { 'a', 'b', 'c', 'd', 0 };  
  cout << my_strlen(arr) << endl;

  return 0;
}
