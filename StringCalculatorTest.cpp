#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int convertToInt(string text) {
  return atoi(text.c_str());
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  return convertToInt(numbers);
}

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}

TEST(StringCalculator, ReturnsOneForSingleOne) {
  ASSERT_THAT(add("1"), Eq(1));
}

TEST(StringCalculator, ReturnsSameNumberForStringWithOneCharacter) {
  ASSERT_THAT(add("3"), Eq(3));
}



