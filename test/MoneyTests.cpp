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

TEST(Money, MoneyMultiplyInteger) {
    Money m1(100);
    Money m2 = m1 * 2;
    EXPECT_EQ(m2.getAmount(), 200);
}

TEST(Money, MoneyMultiplyDouble) {
    Money m1(100);
    Money m2 = m1 * 2.0;
    EXPECT_EQ(m2.getAmount(), 20000);
}

TEST(Money, MoneyDivideInteger) {
    Money m1(100);
    Money m2 = m1 / 2;
    EXPECT_EQ(m2.getAmount(), 50);
}

TEST(Money, MoneyDivideDouble) {
    Money m1(100);
    Money m2 = m1 / 2.0;
    EXPECT_EQ(m2.getAmount(), 0);
}

TEST(Money, MoneyEquals) {
    Money m1(100);
    Money m2 = Money::from_double(2.5);
    m1 = m2;
    EXPECT_EQ(m1.getAmount(), 250);
}

TEST(Money, MoneyEquivalenceTrue) {
    Money m1(100);
    Money m2(100);
    bool b1 = (m1 == m2);
    EXPECT_EQ(b1, true);
}

TEST(Money, MoneyEquivalenceFalse) {
    Money m1(100);
    Money m2(200);
    bool b1 = (m1 == m2);
    EXPECT_EQ(b1, false);
}

TEST(Money, MoneyNotEqualTrue) {
    Money m1(100);
    Money m2(200);
    bool b1 = (m1 != m2);
    EXPECT_EQ(b1, true);
}

TEST(Money, MoneyNotEqualFalse) {
    Money m1(100);
    Money m2(100);
    bool b1 = (m1 != m2);
    EXPECT_EQ(b1, false);
}

TEST(Money, MoneyLessThan) {
    Money m1 = Money::from_double(1.6);
    Money m2(30);
    bool b1 = (m1 < m2);
    bool b2 = (m2 < m1);
    EXPECT_EQ(b1, false);
    EXPECT_EQ(b2, true);    
}

TEST(Money, MoneyGreaterThan) {
    Money m1 = Money::from_double(1.6);
    Money m2(30);
    bool b1 = (m1 > m2);
    bool b2 = (m2 > m1);
    EXPECT_EQ(b1, true);
    EXPECT_EQ(b2, false);    
}

TEST(Money, MoneyLessThanEqualTo) {
    Money m1 = Money::from_double(1.6);
    Money m2(30);
    Money m3(30);
    bool b1 = (m1 <= m2);
    bool b2 = (m2 <= m1);
    bool b3 = (m2 <= m3);
    EXPECT_EQ(b1, false);
    EXPECT_EQ(b2, true); 
    EXPECT_EQ(b3, true);   
}

TEST(Money, MoneyGreaterThanEqualTo) {
    Money m1 = Money::from_double(1.6);
    Money m2(30);
    Money m3(30);
    bool b1 = (m1 >= m2);
    bool b2 = (m2 >= m1);
    bool b3 = (m3 >= m2);
    EXPECT_EQ(b1, true);
    EXPECT_EQ(b2, false);
    EXPECT_EQ(b3, true);    
}
