#include "../include/twelve.h"
#include <gtest/gtest.h>
TEST(HexConstructorTest, DefaultConstructor) {
    Twelve h;
    EXPECT_EQ(h.getSize(), 0);
    EXPECT_EQ(h.toString(), "0");
}

TEST(HexConstructorTest, SizeValueConstructor) {
    Twelve h(4, 6);
    EXPECT_EQ(h.getSize(), 4);
    EXPECT_EQ(h.toString(), "6666");
}

TEST(HexConstructorTest, InitializerListConstructor) {
    Twelve h({1, 2, 3});
    EXPECT_EQ(h.getSize(), 3);
    EXPECT_EQ(h.toString(), "321");
}

TEST(HexConstructorTest, StringConstructor) {
    Twelve h1("ABC");
    EXPECT_EQ(h1.toString(), "ABC");

    Twelve h2("123");
    EXPECT_EQ(h2.toString(), "123");

    Twelve h3("aB");
    EXPECT_EQ(h3.toString(), "AB");
}

TEST(HexConstructorTest, CopyConstructor) {
    Twelve original("AB");
    Twelve copy(original);
    EXPECT_EQ(copy.toString(), "AB");
}

TEST(HexConstructorTest, MoveConstructor) {
    Twelve original("AB");
    Twelve moved(std::move(original));
    EXPECT_EQ(moved.toString(), "AB");
    EXPECT_EQ(original.getSize(), 0);
}

TEST(HexConstructorTest, InvalidHexDigit) {
    EXPECT_THROW(Twelve(1, 16), std::invalid_argument);
    EXPECT_THROW(Twelve({1, 16, 3}), std::invalid_argument);
}



TEST(HexArithmeticTest, Subtraction) {
    Twelve a("123");
    Twelve b("2");
    Twelve diff = a.add(b);
    EXPECT_EQ(diff.toString(), "125");
}


TEST(HexArithmeticTest, SubtractionThrows) {
    Twelve a("3A");
    Twelve b("AC");
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
}

TEST(HexComparisonTest, GreaterThan) {
    Twelve a("B");
    Twelve b("A");
    EXPECT_TRUE(a.isBiggerThan(b));
    EXPECT_FALSE(b.isBiggerThan(a));
}


TEST(HexComparisonTest, Equal) {
    Twelve a("A5");
    Twelve b("A5");
    Twelve c("23");
    EXPECT_TRUE(a.isEqual(b));
    EXPECT_FALSE(a.isEqual(c));
}

TEST(HexAccessTest, GetDigit) {
    Twelve h("AB");
    EXPECT_EQ(h.getDigit(0), 0xB);
    EXPECT_EQ(h.getDigit(1), 0xA);
}

TEST(HexAccessTest, GetDigitThrows) {
    Twelve h("AB");
    EXPECT_THROW(h.getDigit(2), std::out_of_range);
}

TEST(HexEdgeCaseTest, EmptyString) {
    Twelve h("");
    EXPECT_EQ(h.toString(), "0");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}