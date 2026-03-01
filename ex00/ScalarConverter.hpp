#pragma once

#include <iostream>
#include <cstdlib>
class ScalarConverter {
public:
  static void convert(const std::string literal);
private:
  ScalarConverter& operator=(const ScalarConverter& obj);
  virtual ~ScalarConverter() = 0;
  ScalarConverter(const ScalarConverter& obj);
  ScalarConverter();
  static std::string toChar(const std::string &s);
  static std::string toInt(const std::string &s);
  static std::string toFloat(const std::string &s);
  static std::string toDouble(const std::string &s);
  static bool isInvalidInput(const std::string &s);
};

std::ostream&	operator<<(std::ostream& os, const ScalarConverter&obj);

