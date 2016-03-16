
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main(int argc, char** argv)
{
    // std::list<>
    std::vector<std::string> lines;

    std::string line;
    while(std::getline(std::cin, line))
    {
        lines.push_back(line);
    }

    for(int i =0; i < lines.size() ; ++i)
    {
        std::cout << lines[i] << std::endl;
    }

    std::cout << "------------" << std::endl;

    for(std::vector<std::string>::reverse_iterator it = lines.rbegin();
        it != lines.rend();
        ++it
            )
    {
        std::cout << *it << std::endl;
    }

    std::cout << "------------" << std::endl;

    // std::sort
    std::reverse(lines.begin(), lines.end());

    for(auto it = lines.begin();
        it != lines.end();
        ++it
            )
    {
        std::cout << &*it << " " << *it << std::endl;
    }

    std::cout << "------------" << std::endl;
    for(std::string const& line: lines)
    {
        std::cout << line << std::endl;
    }

    return 0;
}
