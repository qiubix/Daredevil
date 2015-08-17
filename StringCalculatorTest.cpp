#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int add(string numbers) {
  if (numbers == "1")
    return 1;
  return 0;
}

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}

TEST(StringCalculator, ReturnsOneForSingleOne) {
  ASSERT_THAT(add("1"), Eq(1));
}
