# CMakeLists.txt

cmake_minimum_required(VERSION 3.20)  # Adjust the version as needed
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 20)

# Add all your source files
set(SOURCES
    src/Address.cpp
    src/IndexNumber.cpp
    src/Name.cpp
    src/Pesel.cpp
    src/Sex.cpp
    src/Source.cpp
    src/Student.cpp
    src/StudentDataBase.cpp
    src/Utils.cpp
)

# Add the executable
add_executable(StudentDatabase ${SOURCES})

