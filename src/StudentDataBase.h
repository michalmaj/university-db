#pragma once

#include <vector>
#include "Student.h"

class StudentDataBase {
public:
  void addStudent();
  void printStudents() const;
  void findStudentByName() const;
  void findStudentByPesel() const;
  void sortByStudentName();
  void sortStudentByPesel();
  void deleteStudentByIndex(size_t index);
  void saveToFile(const std::string &fileName = "myDataBase.txt") const;
  void loadFromFile(const std::string &fileName = "myDataBase.txt");

private:
  Student student_;
  std::vector<Student> students_;
};
