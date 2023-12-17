#include "Name.h"

std::ostream& operator<<(std::ostream &out, const Name &n) {
  out << n.firstName_ << " " << n.lastName_;
  return out;
}

std::istream &operator>>(std::istream &in, Name &n) {
  in >> n.firstName_ >> n.lastName_;
  return in;
}

std::string Name::getFirstName() const {return firstName_;}
std::string Name::getLastName() const { return lastName_; }

bool Name::operator<(const Name &other) const { return lastName_ < other.lastName_; }
