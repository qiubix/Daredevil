#include "gmock/gmock.h"
#include "StringCalculator.hpp"
using ::testing::Eq;
using ::testing::Pointee;

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}

TEST(StringCalculator, ReturnsOneForSingleOne) {
  ASSERT_THAT(add("1"), Eq(1));
}

TEST(StringCalculator, ReturnsSameNumberForStringWithOneNumber) {
  ASSERT_THAT(add("3"), Eq(3));
  ASSERT_THAT(add("15"), Eq(15));
  ASSERT_THAT(add("1423"), Eq(1423));
}

TEST(StringCalculator, ReturnsZeroWhileSummingUpTwoZeros) {
  ASSERT_THAT(add("0,0"), Eq(0));
}

TEST(StringCalculator, SumsTwoNumbers) {
  ASSERT_THAT(add("12,23"), Eq(35));
}

TEST(StringCalculator, SumsThreeNumbers) {
  ASSERT_THAT(add("23,2,100"), Eq(125));
}

TEST(StringCalculator, AllowsNewLineAsADelimiter) {
  ASSERT_THAT(add("23\n2"), Eq(25));
}

TEST(StringCalculator, SupportsDifferentDelimiters) {
  ASSERT_THAT(add("//-\n16-4"), Eq(20));
}

TEST(StringCalculator, ThrowsNegativesAreNotAllowedExceptionForOneNegativeNumber) {
  ASSERT_THROW(add("16,-4"), NegativesAreNotAllowed);
}

TEST(StringCalculator, ListsOneNegativeNumberInExceptionMessage) {
  try {
    add("16,-4");
    FAIL();
  } catch (NegativesAreNotAllowed& ex) {
    ASSERT_THAT(string(ex.what()), Eq(string("Negatives are not allowed: -4")));
  }
}

TEST(StringCalculator, ListsTwoNegativeNumbersInExceptionMessage) {
  try {
    add("-23,-7");
    FAIL();
  } catch (NegativesAreNotAllowed& ex) {
    ASSERT_THAT(string(ex.what()), Eq(string("Negatives are not allowed: -23,-7")));
  }
}

