
#include <iostream>

int main(int argc, char* argv[])
{
  using namespace std;

  const int i = 5;

  const int* i_ptr = &i;
  const int& i_ref = i;

  cout << i << endl;

  cout << &i << endl;
  cout << i_ptr << endl;
  cout << &i_ref << endl;

  cout << *i_ptr << endl;
  cout << i_ref << endl;

  int* i_nonconst_ptr = const_cast<int*>(&i);
  int& i_nonconst_ref = const_cast<int&>(i);

  // i++ // compile error
  cout << "base" << endl;
  cout << i << endl;
  cout << *i_ptr << endl;
  cout << i_ref << endl;
  
  (*i_nonconst_ptr)++;
  cout << "(*i_nonconst_ptr)++" << endl;
  cout << i << endl;
  cout << *i_ptr << endl;
  cout << i_ref << endl;

  i_nonconst_ref++;
  cout << "i_nonconst_ref++" << endl;
  cout << i << endl;
  cout << *i_ptr << endl;
  cout << i_ref << endl;

  return 0;
}
