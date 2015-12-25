#include "gmock/gmock.h"
#include "StringCalculator.hpp"
using ::testing::Eq;
using ::testing::Pointee;

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}

TEST(StringCalculator, ReturnsTheSameNumberForSingleNumber) {
  ASSERT_THAT(add("1"), Eq(1));
  ASSERT_THAT(add("2"), Eq(2));
}

TEST(StringCalculator, SumsTwoSingleDigitNumbers) {
  ASSERT_THAT(add("1,1"), Eq(2));
  ASSERT_THAT(add("1,2"), Eq(3));
}

TEST(StringCalculator, SumsNumbersWithMoreThanOneDigit) {
  ASSERT_THAT(add("11,12"), Eq(23));
  ASSERT_THAT(add("213,112"), Eq(325));
}

TEST(StringCalculator, SumsUnknownAmountOfNumbers) {
  ASSERT_THAT(add("1,1,1"), Eq(3));
  ASSERT_THAT(add("1,10,100,1000"), Eq(1111));
}
