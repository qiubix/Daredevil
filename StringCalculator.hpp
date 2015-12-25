#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

bool hasOnlyOneNumber(const string& numbers) {
  return numbers.find(',') == string::npos;
}

string head(const string& numbers) {
  size_t delimiterPosition = numbers.find(',');
  return numbers.substr(0, delimiterPosition);
}

string tail(const string& numbers) {
  size_t delimiterPosition = numbers.find(',');
  return numbers.substr(delimiterPosition + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else if (hasOnlyOneNumber(numbers))
    return toInt(numbers);
  else
    return toInt(head(numbers)) + toInt(tail(numbers));
}

#endif //STRING_CALCULATOR_HPP
