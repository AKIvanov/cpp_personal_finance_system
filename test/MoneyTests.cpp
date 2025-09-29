#include <gtest/gtest.h>
#include "Money.hpp"

TEST(Money, ConstructWithInteger) {
    Money m1(123);               // or Money m1{"$123.00"} etc.
    EXPECT_EQ(m1.getAmount(), 123); // use EXPECT_DOUBLE_EQ if it's double
}

TEST(Money, ConstructWithDouble) {
    double d1 = 1245.24;
    Money m1 = Money::from_double(d1);               // or Money m1{"$123.00"} etc.
    EXPECT_EQ(m1.getAmount(), 124524); // use EXPECT_DOUBLE_EQ if it's double
}

TEST(Money, ConstructWithString) {
    std::string str = "123.24";
    Money m1 = Money::from_string(str);               // or Money m1{"$123.00"} etc.
    EXPECT_EQ(m1.getAmount(), 12324); // use EXPECT_DOUBLE_EQ if it's double
}

TEST(Money, ConstructWithStringDollarSign) {
    std::string str = "$123.24";
    Money m1 = Money::from_string(str);               // or Money m1{"$123.00"} etc.
    EXPECT_EQ(m1.getAmount(), 12324); // use EXPECT_DOUBLE_EQ if it's double
}

TEST(Money, MoneyAddition) {
    Money m1(123);
    Money m2 = Money::from_double(100.00);
    Money m3 = m1 + m2;
    EXPECT_EQ(m3.getAmount(), 10123); // use EXPECT_DOUBLE_EQ if it's double
}

TEST(Money, MoneySubtract) {
    Money m1(123);
    Money m2 = Money::from_double(101.23);
    Money m3 = m2 - m1;
    EXPECT_EQ(m3.getAmount(), 10000); // use EXPECT_DOUBLE_EQ if it's double
}

