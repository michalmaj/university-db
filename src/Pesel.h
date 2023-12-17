/*
 * Klasa do obsługi numeru Pesel. W tym przypadku zdecydowano się na przechowywanie w zmiennej typu size_t.
 * Weryfikacja poprawności oparta jest o sprawdzenie z ilu cyfr składa się pesel oraz sprawdzenie z cyfrą
 * kontrolną.
*/

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
