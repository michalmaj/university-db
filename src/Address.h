/*
 * Klasa do przechowywania adresu. Na ten moment jest to uproszczona wersja, ponieważ adres jest traktowany
 * jako pojedyczny ciąg znaków. Należałby rozważyć podzielenie adresu na poszczególne składowe.
*/

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


