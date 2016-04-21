
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

class GreaterThanSomething
{
    int m;
public:
    GreaterThanSomething(int m) : m(m) {}
    bool operator()(std::pair<int, std::string> const& p)
    {
        return p.first > m;
    }
};

int main(int argc, char** argv)
{
    std::map<int, std::string> m;
	// std::map<int, std::string, std::greater<int> > m;
	// std::unordered_map<int, std::string> m;

	m[5] = "alma";
	m[3] = "korte";
	m[5] = "barack";
	m[4] = "narancs";

    for(auto i: m)
    {
        std::cout << i.first << " : " << i.second << std::endl;
    }

	std::cout << m[3] << std::endl;

	std::map<int, std::string> const& c = m;

	// std::cout << c[3] << std::endl;
	std::cout << c.at(3) << std::endl;

	try
	{
		std::cout << c.at(9) << std::endl;
	} catch(std::out_of_range oor)
	{
		std::cerr << "Nincs benne 9!" << std::endl;
	}

	auto it = c.find(9);
	if (it != c.end())
	{
		std::cout << it->second << std::endl;
	}

	std::cout << std::find_if(m.begin(), m.end(), GreaterThanSomething(4))->first << std::endl;
	std::cout << std::find_if(m.begin(), m.end(), [](auto& i) { return i.first > 4; })->first << std::endl;
	
	int min = 4;
	// [], [&], [=], ... see: http://en.cppreference.com/w/cpp/language/lambda
	std::cout << std::find_if(m.begin(), m.end(), [/*&*/min](auto& i) { return i.first > min; })->first << std::endl;

    return 0;
}
