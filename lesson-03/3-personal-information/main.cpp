
#include <string>
#include <iostream>


class personal_information
{
  public:
    
    void read(std::istream& is)
    {
      is >> first_name >> last_name;
    }

    void print(std::ostream& os)
    {
      os << "first name: " << first_name << std::endl << "last name: " << last_name << std::endl;
    }

  private:
    std::string first_name;
    std::string last_name;
};


int main(int argc, char* argv[])
{
  personal_information pi;

  pi.read(std::cin);

  // pi.first_name // forditasi hiba

  pi.print(std::cout);
  //pi.print(std::cerr);

  return 0;
}
