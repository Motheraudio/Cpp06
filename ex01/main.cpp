#include "Serializer.hpp"

int main()
{
	Data hehe;
	uintptr_t hoho;
	std::cout << &hehe << std::endl;
	hoho = Serializer::serialize(&hehe);
	std::cout << hoho << std::endl;
	Data* lol;
	lol = Serializer::deserialize(hoho);
	std::cout << lol << std::endl;
}
