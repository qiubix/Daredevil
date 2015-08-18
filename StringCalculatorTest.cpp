#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int convertToInt(string text) {
  return atoi(text.c_str());
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  int sum = 0;
  size_t position;
  while ( (position = numbers.find(",")) != string::npos ) {
    sum += convertToInt(numbers.substr(0,position));
    numbers.erase(0, position + 1);
  }
  return convertToInt(numbers);
}

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

TEST(StringCalculator, ReturnsOneForTwoNumbers) {
  ASSERT_THAT(add("0,1"), Eq(1));
}

