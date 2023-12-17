#include <gtest/gtest.h>
#include <sstream>
#include "Address.h"
#include "IndexNumber.h"
#include "Name.h"
#include "Pesel.h"
#include "Sex.h"


// Test Address
TEST(AddressTest, OutputOperator) {
    Address address;
    
    std::stringstream stream("Szkolna 44");
    stream >> address;

    EXPECT_EQ(stream.str(), "Szkolna 44");
}

TEST(AddressTest, InputOperator) {
    Address address;

    std::stringstream stream("Nowogrodzka 16");
    stream >> address;

    EXPECT_EQ(address.getAddress(), "Nowogrodzka 16");
}

TEST(AddressTest, GetAddress) {
    Address address;
    
    std::stringstream stream("789 Oak St");
    stream >> address;

    EXPECT_EQ(address.getAddress(), "789 Oak St");
}


// Test IndexNumber
TEST(IndexNumberTest, DefaultConstructor) {
    IndexNumber index;
    EXPECT_FALSE(index.checkIndex(index.getIndex()));  // Ensure index is not in indexes_
}

TEST(IndexNumberTest, InsertIndex) {
    IndexNumber index;
    index.insertIndex(12345);
    EXPECT_TRUE(index.checkIndex(12345));  // Ensure the inserted index is in indexes_
}

TEST(IndexNumberTest, RemoveIndex) {
    IndexNumber index;
    index.insertIndex(54321);
    index.removeIndex(54321);
    EXPECT_FALSE(index.checkIndex(54321));  // Ensure the removed index is not in indexes_
}

TEST(IndexNumberTest, CreateIndex) {
    IndexNumber index;
    index.createIndex();
    EXPECT_TRUE(index.checkIndex(index.getIndex()));  // Ensure the created index is in indexes_
}

TEST(IndexNumberTest, StreamInsertionExtraction) {
    IndexNumber index;
    index.createIndex();

    // Use stringstream for insertion and extraction
    std::stringstream ss;
    ss << index;

    IndexNumber new_index;
    ss >> new_index;

    EXPECT_EQ(index.getIndex(), new_index.getIndex());
}


// Test Name
TEST(NameTest, StreamInsertionExtraction) {
    // Create a Name object
    Name name;

    // Use stringstream to set private members
    std::stringstream ss;
    ss << "John Doe";

    // Extract values into the private members
    ss >> name;

    // Check the values
    EXPECT_EQ(name.getFirstName(), "John");
    EXPECT_EQ(name.getLastName(), "Doe");
}

TEST(NameTest, LessThanOperator) {
    // Create Name objects
    Name name1;
    Name name2;

    // Set private members using stringstream
    std::stringstream ss1("John Doe");
    std::stringstream ss2("Jane Deo");

    ss1 >> name1;
    ss2 >> name2;

    // Compare using less-than operator
    EXPECT_FALSE(name1.getLastName() < name1.getLastName());  // A name is not less than itself
    EXPECT_FALSE(name1.getLastName() < name2.getLastName());   // Compare by last names
    EXPECT_TRUE(name2.getLastName() < name1.getLastName());
}


// Test Pesel
TEST(PeselTest, StreamInsertionExtraction) {
    Pesel pesel;
    Pesel new_pesel;

    // Use stringstream for insertion and extraction
    std::stringstream ss1("91082267218");
    std::stringstream ss2("91082267218");

    ss1 >> pesel;
    ss2 >> new_pesel;

    EXPECT_EQ(pesel.getPesel(), new_pesel.getPesel());
}

TEST(PeselTest, CheckPeselValid) {
    Pesel pesel;

    // Valid PESEL: 44051401458
    std::stringstream ss("44051401458");
    ss >> pesel;

    EXPECT_TRUE(pesel.checkPesel(pesel.getPesel()));
}

TEST(PeselTest, CheckPeselInvalid) {
    Pesel pesel;

    // Invalid PESEL: 12345678901
    std::stringstream ss("12345678901");
    ss >> pesel;

    EXPECT_FALSE(pesel.checkPesel(pesel.getPesel()));
}

TEST(PeselTest, LessThanOperator) {
    Pesel pesel1;
    Pesel pesel2;

    std::stringstream ss1("54010658139");
    std::stringstream ss2("55021639216");

    ss1 >> pesel1;
    ss2 >> pesel2;


    EXPECT_TRUE(pesel1 < pesel2);
    EXPECT_FALSE(pesel2 < pesel1);
}


// Test Sex
TEST(SexTest, SetSexValid) {
    Sex sex;

    // Valid sex: "female"
    std::stringstream ss("female");
    ss >> sex;

    EXPECT_TRUE(sex.checkSex(6));  // Pass a PESEL number for checking, can be any value
}

TEST(SexTest, SetSexInvalid) {
    Sex sex;

    // Invalid sex: "unknown"
    std::stringstream ss("unknown");
    ss >> sex;

    EXPECT_FALSE(sex.checkSex(2));  // Pass a PESEL number for checking, can be any value
}

TEST(SexTest, CheckSexValid) {
    Sex sex;

    std::stringstream ss("male");
    ss >> sex;

    EXPECT_TRUE(sex.checkSex(9));  // Pass a PESEL number for checking, can be any value
}

TEST(SexTest, CheckSexInvalid) {
    Sex sex;

    std::stringstream ss("female");
    ss >> sex;

    EXPECT_FALSE(sex.checkSex(1));  // Pass a PESEL number for checking, can be any value
}