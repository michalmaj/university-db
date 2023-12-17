#include <random>

#include "IndexNumber.h"

std::ostream &operator<<(std::ostream &out, const IndexNumber &index_number) {
  out << index_number.index_;
  return out;
}

std::istream &operator>>(std::istream &in, IndexNumber &index_number) {
  index_number.insertIndex(index_number.index_);
  in >> index_number.index_;
  return in;
}

bool IndexNumber::checkIndex(size_t val) const {
  if (indexes_.find(val) != indexes_.end())
    return true;
  return false;
}


void IndexNumber::createIndex() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> distribution(10'000, 99'999);
  size_t val = distribution(gen);
  while (checkIndex(val))
    val = distribution(gen);
  index_ = val;
  indexes_.insert(val);
}

void IndexNumber::insertIndex(size_t val) { indexes_.insert(val); }


void IndexNumber::removeIndex(size_t val) { indexes_.erase(val); }


size_t IndexNumber::getIndex() const { return index_; }