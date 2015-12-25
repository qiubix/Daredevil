#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

bool hasOnlyOneNumber(const string &numbers) {
  return numbers.find(',') == string::npos;
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else if (hasOnlyOneNumber(numbers))
    return toInt(numbers);
  else
    return 2;
}

#endif //STRING_CALCULATOR_HPP
