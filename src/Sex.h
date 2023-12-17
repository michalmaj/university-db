#pragma once

#include <iostream>

class Sex {
  friend std::ostream &operator<<(std::ostream &out, const Sex &s);
  friend std::istream &operator>>(std::istream &in, Sex &s);

public:
  std::string getSex() const;
  void setSex(unsigned int val);
  bool checkSex(unsigned int val) const;

private:
  std::string sex_;
};
