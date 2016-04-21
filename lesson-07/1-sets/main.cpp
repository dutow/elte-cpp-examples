
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <functional>

int main(int argc, char** argv)
{
	std::set< int > s;
    // std::set< int, std::greater<int> > s;
	// std::unordered_set<int> s;

	s.insert(3);
	s.insert(5);
	s.insert(2);
	
    for(auto i: s)
    {
		// order!
        std::cout << i << std::endl;
    }

	std::cout << *s.find(3) << std::endl;

    return 0;
}
