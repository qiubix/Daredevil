#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

bool hasOnlyOneNumber(string text) {
  return text.find(',') == string::npos;
}

string head(string text, size_t delimiterPosition) {
  return text.substr(0, delimiterPosition);
}

string tail(string text, size_t delimiterPosition) {
  return text.substr(delimiterPosition + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else if (hasOnlyOneNumber(numbers))
    return toInt(numbers);
  else {
    auto delimiterPosition = numbers.find(',');
    return toInt(head(numbers, delimiterPosition)) + toInt(tail(numbers, delimiterPosition));
  }
}

#endif //STRING_CALCULATOR_HPP
