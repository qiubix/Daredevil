#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else
    return toInt(numbers);
}

#endif //STRING_CALCULATOR_HPP
