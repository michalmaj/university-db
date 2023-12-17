#pragma once

#include <iostream>

class Pesel {
  friend std::ostream &operator<<(std::ostream &out, const Pesel &p);
  friend std::istream &operator>>(std::istream &in, Pesel &p);

public:
  size_t getPesel() const;
  bool checkPesel(size_t p) const;
  void setPesel();

  bool operator<(const Pesel &other) const;

private:
  size_t pesel_;
};
