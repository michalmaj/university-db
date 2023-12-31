#include "Address.h"

std::ostream &operator<<(std::ostream &out, const Address &a) {
  out << a.address_;
  return out;
}

std::istream &operator>>(std::istream &in, Address &a) {
  std::getline(in >> std::ws, a.address_);
  return in;
}


std::string Address::getAddress() const {return address_;}