
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }

    std::cout << "program vege!";

    return 0;
}
