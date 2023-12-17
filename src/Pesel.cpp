#include "Pesel.h"

#include <numeric>
#include <deque>
#include <vector>

std::ostream &operator<<(std::ostream &out, const Pesel &p) {
  out << p.pesel_;
  return out;
}

std::istream &operator>>(std::istream &in, Pesel &p) {
  in >> p.pesel_;
  return in;
}

size_t Pesel::getPesel() const { return pesel_; }
bool Pesel::checkPesel(size_t p) const {
  std::deque<unsigned int> pesel;
  while (p > 0) {
    pesel.push_front(p % 10);
    p /= 10;
  }
  if (pesel.size() != 11)
    return false;

  const std::vector<unsigned int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
  auto res =
      std::transform_reduce(pesel.begin(), pesel.end() - 1, weights.begin(), 0,
                            std::plus{}, std::multiplies{});

  if (pesel.at(10) == 0 and res % 10 == 0)
    return true;
  if (pesel.at(10) == 10 - res % 10)
    return true;

  return false;
}


void Pesel::setPesel() {
  std::cin >> pesel_;
  while (!checkPesel(pesel_)) {
    std::cout << "Wrong pesel number! Enter correct one: ";
    std::cin >> pesel_;
  }
}


bool Pesel::operator<(const Pesel &other) const { return pesel_ < other.pesel_; }