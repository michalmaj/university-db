#pragma once
#include <iostream>

class Address {
  friend std::ostream &operator<<(std::ostream &out, const Address &a);
  friend std::istream &operator>>(std::istream &in, Address &a);

public:
  std::string getAddress() const; 

private:
  std::string address_;
};


