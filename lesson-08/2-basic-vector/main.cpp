
#include <iostream>
#include "vector.h"


int main(int argc, char** argv)
{
	mystd::vector<int> vec;

	vec.push_back(3);
	vec.push_back(5);

	std::cout << vec[1] << std::endl;

    return 0;
}
