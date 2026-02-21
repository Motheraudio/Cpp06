#pragma once

#include <iostream>

class ScalarConverter {
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& obj);
  virtual ~ScalarConverter() = 0;
  static void convert(const std::string literal);
  ScalarConverter& operator=(const ScalarConverter& obj);
private:
  std::string toChar(std::string &s);
};

std::ostream&	operator<<(std::ostream& os, const ScalarConverter&obj);

