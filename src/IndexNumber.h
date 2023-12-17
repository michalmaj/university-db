/*
 * Klas do generowania losowego indeksu. Związane jest to z tym, że użytkownik nie powinien móc generować własnego
 * indeksu ze względu na możliwość wystąpienia kolizji.
 * Wygenerowane indeksy są przechowywane w unordered_set. Jeśli podczas tworzenia studenta w kolekcji jest już
 * taki indeks, generowany jest kolejny. Jeśli student jest usuwany, także jego indeks jest usuwany z kolekcji. 
*/

#pragma once
#include <iostream>
#include <unordered_set>

class IndexNumber {
  friend std::ostream &operator<<(std::ostream &out, const IndexNumber &index_number);
  friend std::istream &operator>>(std::istream &in, IndexNumber &index_number);

  public:
  bool checkIndex(size_t val) const;
  void createIndex();
  void removeIndex(size_t val);
  size_t getIndex() const;
  void insertIndex(size_t val);


private:
  size_t index_;
  inline static std::unordered_set<size_t> indexes_;
};
