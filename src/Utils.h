#pragma once

#include "StudentDataBase.h"

class UniversitySystem {
public:
  void run();

private:
  int menu();
  StudentDataBase sdb;
};


