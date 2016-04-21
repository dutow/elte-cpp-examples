
#include <iostream>

namespace other
{
	struct S
	{
		int i;
	};

	S const& max(S const& a, S const& b)
	{
		std::cout << "S overload max" << std::endl;
		return a.i > b.i ? a : b;
	}

	std::ostream& operator<<(std::ostream& out, S const& s)
	{
		out << s.i;
		return out;
	}

	bool operator>(S const& a, S const& b)
	{
		return a.i > b.i;
	}
}

namespace mystd
{
	template<typename T>
	T const& max(T const& a, T const& b)
	{
		std::cout << "generic template max" << std::endl;
		return a > b ? a : b;
	}

	template<>
	int const& max(int const& a, int const& b)
	{
		std::cout << "int template max" << std::endl;
		return a > b ? a : b;
	}

	double max(double const& a, float const& b)
	{
		std::cout << "double-float overload max" << std::endl;
		return a > b ? a : b;
	}
}

int main(int argc, char** argv)
{
	std::cout << mystd::max(4, 5) << std::endl;
	std::cout << mystd::max(4, 5.3f) << std::endl;
	std::cout << mystd::max(4.2, 5.f) << std::endl;
	std::cout << mystd::max(4, 5.) << std::endl;

	std::cout << mystd::max(other::S{1}, other::S{5}) << std::endl;

	using namespace mystd;
	std::cout << max(other::S{ 1 }, other::S{ 5 }) << std::endl;

    return 0;
}
