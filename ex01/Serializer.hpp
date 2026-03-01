#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>
class Serializer {
public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
private:
  Serializer();
  virtual ~Serializer() = 0;
  Serializer& operator=(const Serializer& obj);
  Serializer(const Serializer& obj);
};

std::ostream&	operator<<(std::ostream& os, const Serializer&obj);

