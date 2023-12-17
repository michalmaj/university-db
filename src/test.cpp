#include <gtest/gtest.h>
#include <sstream>
#include "Address.h"

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
