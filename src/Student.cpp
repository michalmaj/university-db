#include <iostream>

#include "Student.h"

std::ostream &operator<<(std::ostream &out, const Student &s) {
  out << s.name_ << "\n";
  out << s.address_ << "\n";
  out << s.indexNumber_ << "\n";
  out << s.pesel_ << "\n";
  out << s.sex_ << "\n";
  return out;
}

std::istream &operator>>(std::istream &in, Student &s) {
  in >> s.name_;
  in >> s.address_;
  in >> s.indexNumber_;
  in >> s.pesel_;
  in >> s.sex_;
  return in;
}

Name Student::getName() const { return name_; }

void Student::addStudent() {
  std::cout << "Enter your first name and last name: ";
  std::cin >> name_;

  std::cout << "Enter your address: ";
  std::cin >> address_;

  indexNumber_.createIndex();

  std::cout << "Enter your pesel number: ";
  pesel_.setPesel();

  std::cout << "Enter your sex (male or female): ";
  sex_.setSex((pesel_.getPesel() / 10) % 10);
}


void Student::printStudent() const {
  std::cout << "Student's name: " << name_ << "\n";
}

bool Student::findStudentByName(std::string_view last_name) const {
  return last_name == name_.getLastName();
}

bool Student::findStudentByIndex(size_t index) const {
  return index == indexNumber_.getIndex();
}

void Student::removeIndex(size_t index) { indexNumber_.removeIndex(index); }

size_t Student::getIndex() const { return indexNumber_.getIndex(); }


bool Student::checkIndexCoretness(size_t index) const {
  std::string ind = std::to_string(index);
  if (ind.size() != 5)
    return false;
  if (indexNumber_.checkIndex(index))
    return false;
  return true;
}

size_t Student::getPesel() const { return pesel_.getPesel(); }

bool Student::checkPesel(size_t pesel) const {
  return pesel_.checkPesel(pesel);
}

bool Student::checkSex(unsigned sex) const { return sex_.checkSex(sex); }

