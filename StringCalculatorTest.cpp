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
  int sum = 0;
  while ( position != string::npos ) {
    sum += toInt(numbers.substr(0, position));
    numbers.erase(0, position + 1);
    position = numbers.find(",");
  }
  sum += toInt(numbers);
  return sum;
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

TEST(StringCalculator, SumsThreeNumbers) {
  ASSERT_THAT(add("23,2,100"), Eq(125));
}

