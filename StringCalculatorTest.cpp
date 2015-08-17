#include "gmock/gmock.h"
using ::testing::Eq;
using namespace std;

int add(string numbers) {
  return 0;
}

TEST(StringCalculator, ReturnsZeroForAnEmptyString) {
  ASSERT_THAT(add(""), Eq(0));
}
