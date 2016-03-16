
#include <iostream>

int main(int argc, char** argv)
{
    std::cin >> std::noskipws;

    char c;

    while(std::cin >> c)
    {
        std::cout << c;
    }

    std::cout << "program vege!";

    return 0;
}
