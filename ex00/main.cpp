#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "only one argument plz" << std::endl;
		return (1);
	}
	std::string argument = argv[1];
	ScalarConverter::convert(argument);
}
