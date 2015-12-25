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
