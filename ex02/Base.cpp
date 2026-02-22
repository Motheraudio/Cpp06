#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
Base::~Base(){

}

Base *generate(void)
{
	std::srand(time(NULL));
	int val = rand() % 3;
	if (val == 0)
		return (new A);
	if (val == 1)
		return (new B);
	else
		return (new C);
}
void identify(Base *p)
{

	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}
void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch(...){};
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch(...){};
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch(...){};
}

