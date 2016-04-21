
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
    bool operator()(int const& v)
    {
        return v > m;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> v({3, 4, 5, 9, 6, 2});

    int m = 4;

    auto f = [/*&*/m](int const& i) { return i > m; };

	m = 5;

	// http://en.cppreference.com/w/cpp/algorithm

    auto it = std::remove_if(
            v.begin(),
            v.end(),
            f
    );
    v.erase(it, v.end());

    for(auto i: v)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
