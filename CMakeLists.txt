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
    src/Student.cpp
    src/StudentDataBase.cpp
    src/Utils.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} src/Source.cpp ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}-ut src/test.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
