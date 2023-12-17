/*
 * Klasa pozwala na dodanie imienia i nazwiska dla studenta.
 * Dodano operator pozwalający na sprawdzenie, które nazwisko jest mniejsze alfabetycznie.
*/

#pragma once
#include <iostream>
#include <string>
#include <string_view>

class Name {
  friend std::ostream& operator<<(std::ostream& out, const Name &n);
  friend std::istream &operator>>(std::istream &in, Name &n);

public:
  std::string getFirstName() const;
  std::string getLastName() const;
  bool operator<(const Name &other) const;

private:
  std::string firstName_;
  std::string lastName_;
};
