#include "Sex.h"


std::ostream &operator<<(std::ostream &out, const Sex &s) {
  out << s.sex_;
  return out;
}

std::istream &operator>>(std::istream &in, Sex &s) {
  in >> s.sex_;
  return in;
}

std::string Sex::getSex() const { return sex_; }

void Sex::setSex(unsigned int val) {
  std::cin >> sex_;

  while (!checkSex(val)) {
    std::cout << "Your pesel number suggests different sex! Enter your sex: ";
    std::cin >> sex_;
  }
}


bool Sex::checkSex(unsigned int val) const {
  if (val % 2 == 0 and sex_ == "female")
    return true;
  if (val % 2 == 1 and sex_ == "male")
    return true;
  return false;
}
