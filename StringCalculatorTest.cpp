#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

const vector<string> delimiters = { ",", "\n" };

size_t findDelimiter(const string& text) {
  for ( auto delimiter : delimiters ) {
    auto position = text.find(delimiter);
    if ( position != string::npos )
      return position;
  }
  return text.length();
}

string head(const string& text) {
  auto position = findDelimiter(text);
  return text.substr(0, position);
}

string tail(const string& text) {
  auto position = findDelimiter(text);
  if ( position != text.length() )
    return text.substr(position + 1);
  else
    return text.substr(position);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  int sum = 0;
  while ( numbers != "" ) {
    sum += toInt(head(numbers));
    numbers = tail(numbers);
  }
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

TEST(StringCalculator, AllowsNewLineAsADelimiter) {
  ASSERT_THAT(add("23\n2"), Eq(25));
}

