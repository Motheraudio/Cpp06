#include "Base.hpp"
#include <iostream>
int main()
{
	Base *hehe = generate();
	identify(hehe);
	std::cout << "-----" << std::endl;
	identify(*hehe);
	delete hehe;
}
