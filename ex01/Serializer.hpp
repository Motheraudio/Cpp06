#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>
class Serializer {
public:
  Serializer(const Serializer& obj);
  virtual ~Serializer() = 0;
  Serializer& operator=(const Serializer& obj);
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
private:
  Serializer();
};

std::ostream&	operator<<(std::ostream& os, const Serializer&obj);

