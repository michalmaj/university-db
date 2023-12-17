#pragma once
#include "Address.h"
#include "IndexNumber.h"
#include "Name.h"
#include "Pesel.h"
#include "Sex.h"

class Student {
  friend std::ostream &operator<<(std::ostream &out, const Student &s);
  friend std::istream &operator>>(std::istream &in, Student &s);

public:
  Name getName() const;
  void addStudent();
  void printStudent() const;
  bool findStudentByName(std::string_view last_name) const;
  bool findStudentByIndex(size_t index) const;
  void removeIndex(size_t index);
  size_t getIndex() const;
  bool checkIndexCoretness(size_t index) const;
  size_t getPesel() const;
  bool checkPesel(size_t pesel) const;
  bool checkSex(unsigned int sex) const;

private:
  Name name_;
  Address address_;
  IndexNumber indexNumber_;
  Pesel pesel_;
  Sex sex_;
};

