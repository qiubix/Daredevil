#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else
    return atoi(numbers.c_str());
}

#endif //STRING_CALCULATOR_HPP
