#pragma once

#include <iostream>

class Data {
public:
  Data();
  Data(const Data& obj);
  ~Data();

  Data& operator=(const Data& obj);

private:
  int x;
  char j;
};

std::ostream&	operator<<(std::ostream& os, const Data&obj);

