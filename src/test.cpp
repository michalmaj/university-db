/*
 * Kilka testów sprawdzających poprawność klas.
*/

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
    EXPECT_FALSE(index.checkIndex(index.getIndex()));  
}

TEST(IndexNumberTest, InsertIndex) {
    IndexNumber index;
    index.insertIndex(12345);
    EXPECT_TRUE(index.checkIndex(12345));  
}

TEST(IndexNumberTest, RemoveIndex) {
    IndexNumber index;
    index.insertIndex(54321);
    index.removeIndex(54321);
    EXPECT_FALSE(index.checkIndex(54321));  
}

TEST(IndexNumberTest, CreateIndex) {
    IndexNumber index;
    index.createIndex();
    EXPECT_TRUE(index.checkIndex(index.getIndex()));  
}

TEST(IndexNumberTest, StreamInsertionExtraction) {
    IndexNumber index;
    index.createIndex();

    std::stringstream ss;
    ss << index;

    IndexNumber new_index;
    ss >> new_index;

    EXPECT_EQ(index.getIndex(), new_index.getIndex());
}


// Test Name
TEST(NameTest, StreamInsertionExtraction) {
    Name name;

    std::stringstream ss;
    ss << "John Doe";

    ss >> name;

    EXPECT_EQ(name.getFirstName(), "John");
    EXPECT_EQ(name.getLastName(), "Doe");
}

TEST(NameTest, LessThanOperator) {
    Name name1;
    Name name2;

    std::stringstream ss1("John Doe");
    std::stringstream ss2("Jane Deo");

    ss1 >> name1;
    ss2 >> name2;

    EXPECT_FALSE(name1.getLastName() < name1.getLastName());  
    EXPECT_FALSE(name1.getLastName() < name2.getLastName());   
    EXPECT_TRUE(name2.getLastName() < name1.getLastName());
}


// Test Pesel
TEST(PeselTest, StreamInsertionExtraction) {
    Pesel pesel;
    Pesel new_pesel;

    std::stringstream ss1("91082267218");
    std::stringstream ss2("91082267218");

    ss1 >> pesel;
    ss2 >> new_pesel;

    EXPECT_EQ(pesel.getPesel(), new_pesel.getPesel());
}

TEST(PeselTest, CheckPeselValid) {
    Pesel pesel;

    std::stringstream ss("44051401458");
    ss >> pesel;

    EXPECT_TRUE(pesel.checkPesel(pesel.getPesel()));
}

TEST(PeselTest, CheckPeselInvalid) {
    Pesel pesel;

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

    std::stringstream ss("female");
    ss >> sex;

    EXPECT_TRUE(sex.checkSex(6)); 
}

TEST(SexTest, SetSexInvalid) {
    Sex sex;

    std::stringstream ss("unknown");
    ss >> sex;

    EXPECT_FALSE(sex.checkSex(2)); 
}

TEST(SexTest, CheckSexValid) {
    Sex sex;

    std::stringstream ss("male");
    ss >> sex;

    EXPECT_TRUE(sex.checkSex(9)); 
}

TEST(SexTest, CheckSexInvalid) {
    Sex sex;

    std::stringstream ss("female");
    ss >> sex;

    EXPECT_FALSE(sex.checkSex(1)); 
}

// TODO: dodaj więcej testów