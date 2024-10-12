#include <gtest/gtest.h>
#include "kataTDD.cpp"

TEST(helloTest, saysHelloWorld) {
    EXPECT_EQ(hello(), "Hello World!");
}

TEST(fizzBuzzTest, 1ShouldReturn1) {
    EXPECT_EQ(fizzBuzz(1), "1");
}

TEST(fizzBuzzTest, theseShouldReturnFizzByRule1) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(6), "Fizz");
    EXPECT_EQ(fizzBuzz(9), "Fizz");
    EXPECT_EQ(fizzBuzz(12), "Fizz");
}

TEST(fizzBuzzTest, theseShouldReturnBuzzByRule2) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(10), "Buzz");
}

TEST(fizzBuzzTest, theseShouldReturnFizzBuzzByRule1And2) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
}

TEST(RomanToDecimalTest, convertsCorrectly) {
    RomanToDecimal rtd1("X");
    EXPECT_EQ(rtd1.getDecimal(), 10);

    RomanToDecimal rtd2("IX");
    EXPECT_EQ(rtd2.getDecimal(), 9);

    RomanToDecimal rtd3("MLXIII");
    EXPECT_EQ(rtd3.getDecimal(), 1063);

    RomanToDecimal rtd4("XLIX");
    EXPECT_EQ(rtd4.getDecimal(), 49);
}
