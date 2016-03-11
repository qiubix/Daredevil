#include "gmock/gmock.h"
#include "StringCalculator.hpp"
using ::testing::Eq;
using ::testing::Pointee;

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}

TEST(StringCalculator, ReturnsSameNumberForASingleNumber) {
  ASSERT_THAT(add("1"), Eq(1));
  ASSERT_THAT(add("2"), Eq(2));
  ASSERT_THAT(add("13"), Eq(13));
}

TEST(StringCalculator, ReturnsSumForTwoNumbersWithComa) {
  ASSERT_THAT(add("1,1"), Eq(2));
  ASSERT_THAT(add("2,1"), Eq(3));
  ASSERT_THAT(add("12,11"), Eq(23));
}
