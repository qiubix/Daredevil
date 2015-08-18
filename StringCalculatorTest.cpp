#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  size_t position = numbers.find(",");
  if ( position != string::npos ) {
    return toInt(numbers.substr(0, position)) + toInt(numbers.substr(position + 1));
  }
  return toInt(numbers);
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

TEST(StringCalculator, SumsTwoNumbers) {
  ASSERT_THAT(add("12,23"), Eq(35));
}

