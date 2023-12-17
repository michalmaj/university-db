#include <algorithm>
#include <fstream>
#include <iterator>
#include <ranges>

#include "StudentDataBase.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  for (const auto &e : vec)
    out << e << " ";
  return out;
}

void StudentDataBase::addStudent() {
  student_.addStudent();
  students_.emplace_back(student_);
}

void StudentDataBase::printStudents() const {
  for (const auto &e : students_) {
    std::cout << e << "\n";
  }
}

void StudentDataBase::findStudentByName() const {
  std::string lastName;
  std::cout << "Enter last name to find the student: ";
  std::cin >> lastName;
  std::ranges::for_each(students_, [&lastName](const auto &student) {
    if (student.findStudentByName(lastName))
      std::cout << student << "\n";
  });
}

void StudentDataBase::findStudentByPesel() const {
  size_t pesel;
  std::cout << "Enter pesel number to find the student: ";
  std::cin >> pesel;
  auto res = std::ranges::find_if(students_, [&pesel](const auto &student) {
    return student.getPesel() == pesel;
  });
  if (res != students_.end())
    std::cout << *res << "\n";
}

void StudentDataBase::sortByStudentName() {
  std::ranges::stable_sort(students_, [](const auto &s1, const auto &s2) {
    return s1.getName() < s2.getName();
  });
}

void StudentDataBase::sortStudentByPesel() {
  std::ranges::stable_sort(students_, [](const auto &s1, const auto &s2) {
    return s1.getPesel() < s2.getPesel();
  });
}

void StudentDataBase::deleteStudentByIndex(size_t index) {
  auto erased = std::erase_if(students_, [&index](const auto &s) {
    return s.findStudentByIndex(index);
  });
  if (erased)
    student_.removeIndex(index);
}

void StudentDataBase::saveToFile(const std::string &fileName) const {
  std::ofstream outputFile(fileName);
  if (outputFile.is_open()) {
    std::ranges::copy(students_,
                      std::ostream_iterator<Student>(outputFile, "\n"));

    outputFile.close();

    std::cout << "Data Base has been saved to file." << std::endl;
  } else {
    std::cerr << "Error: Unable to open the file." << std::endl;
  }
}

void StudentDataBase::loadFromFile(const std::string &fileName) {
  std::string yes;
  std::cout << "This operation replace your current data base. Type yes if you "
               "want to continue: ";
  std::cin >> yes;
  if (yes != "yes")
    return;
  students_.clear();
  bool isRead{true};
  std::ifstream inputFile(fileName);
  if (inputFile.is_open()) {
    while (true) {
      if (inputFile >> student_) {
        if (!student_.checkIndexCoretness(student_.getIndex())) {
          std::cout << "Index collision! ";
          std::cout << "Student: " << student_.getName() << " discarded.\n";
          continue;
        }
        if (!student_.checkPesel(student_.getPesel())) {
          std::cout << "Wrong pesel number! ";
          std::cout << "Student: " << student_.getName() << " discarded.\n";
          continue;
        }
        if (!student_.checkSex((student_.getPesel() / 10) % 10)) {
          std::cout << "Pesel number doesn't match student sex! ";
          std::cout << "Student " << student_.getName() << " discarded.\n";
          continue;
        }
        students_.push_back(student_);
      } else {
        if (inputFile.eof())
          break; // end of file
        else {
          std::cerr << "Data base corrupted\n";
          isRead = false;
          break; // Break the loop if there's an error
        }
      }
    }
    inputFile.close();

    if (isRead)
      std::cout << "Data Base has been read from file." << std::endl;
  } else {
    std::cerr << "Error: Unable to open the file." << std::endl;
  }
}
