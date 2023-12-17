#pragma once
#include <iostream>
#include <unordered_set>

class IndexNumber {
  friend std::ostream &operator<<(std::ostream &out, const IndexNumber &index_number);
  friend std::istream &operator>>(std::istream &in, IndexNumber &index_number);

  void insertIndex(size_t val);

  public:
  bool checkIndex(size_t val) const;
  void createIndex();
  void removeIndex(size_t val);
  size_t getIndex() const;


private:
  size_t index_;
  inline static std::unordered_set<size_t> indexes_;
};
