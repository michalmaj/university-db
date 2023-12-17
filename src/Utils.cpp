#include <iostream>
#include "Utils.h"


int UniversitySystem::menu() {
  int choice = -1;
  while (choice == -1) {
    std::cout << "\nLibrary menu:\n";
    std::cout << "1) Add new student.\n";
    std::cout << "2) Print student data base.\n";
    std::cout << "3) Search student by last name.\n";
    std::cout << "4) Search student by PESEL.\n";
    std::cout << "5) Sort by PESEL.\n";
    std::cout << "6) Sort by name.\n";
    std::cout << "7) Delete by Index Number.\n";
    std::cout << "8) Save to file.\n";
    std::cout << "9) Load from file.\n";
    std::cout << "10) Exit\n";

    std::cout << "\nEnter your menu choice [1-10]: ";
    std::cin >> choice;

    if (!(1 <= choice && choice <= 10)) {
      std::cout << "Invalid choice. Try again\n";
      choice = -1;
    }
  }
  return choice;
}

void UniversitySystem::run() {
  while (true) {
    int choice = menu();

    if (choice == 1)
      sdb.addStudent();
    else if (choice == 2)
      sdb.printStudents();
    else if (choice == 3)
      sdb.findStudentByName();
    else if (choice == 4)
      sdb.findStudentByPesel();
    else if (choice == 5)
      sdb.sortStudentByPesel();
    else if (choice == 6)
      sdb.sortByStudentName();
    else if (choice == 7) {
      size_t index;
      std::cout << "Enter index to delete: ";
      std::cin >> index;
      sdb.deleteStudentByIndex(index); 
    }
    else if (choice == 8)
      sdb.saveToFile();
    else if (choice == 9)
      sdb.loadFromFile();
    else if (choice == 10)
      break;
  }
}