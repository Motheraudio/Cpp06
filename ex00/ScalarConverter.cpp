#include "ScalarConverter.hpp"
#include <sstream>
#include <string>
#include <cmath>
ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter& other){(void) other;}

ScalarConverter::~ScalarConverter(){

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){(void)obj; return (*this);}

bool ScalarConverter::isInvalidInput(const std::string &s)
{

	size_t i = 0;
	size_t dotcount = 0;
	while  (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			i++;
		else if (i == s.length() - 1 && s[i] == 'f' && i - 1 >= 0 && s[i - 1] != '.')
			i++;
		else if (s[i] == '.' && dotcount == 0 && i != 0 && i != s.length() - 1)
		{
			i++;
			dotcount++;
		}
		else if (isdigit(s[i]))
			i++;
		else
			return (true);
	}
		return (false);
}

std::string ScalarConverter::toChar(const std::string &s)
{
	if (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]))
		return (s);
	if (ScalarConverter::isInvalidInput(s))
		return ("impossible");
	int numerical = static_cast<int>(std::atoi(s.c_str()));
	const unsigned long dotpos = s.find(".");
	std::stringstream out;
	out << numerical;
	std::string compare = out.str();
	if (dotpos == std::string::npos && compare != s)
		return ("impossible");
	if (dotpos != std::string::npos && s.substr(0, dotpos) != compare)
		return ("impossible");
	if (ScalarConverter::isInvalidInput(s))
		return ("impossible");
	if (numerical < 0 || numerical > 255)
		return ("impossible");
	if (std::isprint(static_cast<unsigned char>(numerical)) == false)
		return ("Non displayable");
	std::string literal(1, static_cast<unsigned char>(numerical));
	return (literal);
}
std::string ScalarConverter::toInt(const std::string &s)
{
	int numerical = static_cast<int>(std::atoi(s.c_str()));
	std::stringstream out;
	if (s.length() == 1 && isascii(s[0]) && !isdigit(s[0]))
	{
		out << static_cast<int>(s[0]);
		return (out.str());
	}
	if (ScalarConverter::isInvalidInput(s))
		return ("impossible");
	out << numerical;
	std::string compare = out.str();
	if (s.find(".") == std::string::npos && compare != s)
		return ("impossible");
	else if (s.find(".") != std::string::npos && s.substr(0, s.find(".")) != compare) 
			return ("impossible");
	return (compare);
}

std::string ScalarConverter::toFloat(const std::string &s)
{
	std::stringstream out;
	if (s == "nan" || s == "-inf" || s == "+inf")
		return (s + "f");
	if (s.length() == 1 && isascii(s[0]) && !isdigit(s[0]))
	{
		out << static_cast<float>(s[0]);
		return (out.str() + ".00f");
	}
	if (ScalarConverter::isInvalidInput(s))
		return ("impossible");
	float numerical = static_cast<float>(std::atof(s.c_str()));
	if (numerical == INFINITY || numerical == -INFINITY)
		return ("impossible");
	out << numerical;
	if (out.str().find(".") == std::string::npos)
		return (out.str() + ".00f");
	return (out.str() + "f");
}
std::string ScalarConverter::toDouble(const std::string &s)
{
	std::stringstream out;
	if (s == "nan" || s == "-inf" || s == "+inf")
		return (s);
	if (s.length() == 1 && isascii(s[0]) && !isdigit(s[0]))
	{
		out << static_cast<double>(s[0]);
		return (out.str() + ".00");
	}
	if (ScalarConverter::isInvalidInput(s))
		return ("impossible");
	double numerical = static_cast<double>(std::atof(s.c_str()));
	if (numerical == INFINITY || numerical == -INFINITY)
		return ("impossible");
	out << numerical;
	if (out.str().find(".") == std::string::npos)
		return (out.str() + ".00");
	return (out.str());
}
void ScalarConverter::convert(const std::string literal)
{
	std::cout << "char: " << ScalarConverter::toChar(literal) << std::endl;
	std::cout << "int: " << ScalarConverter::toInt(literal) << std::endl;
	std::cout << "float: " << ScalarConverter::toFloat(literal) << std::endl;
	std::cout << "double: " << ScalarConverter::toDouble(literal) << std::endl;
}
