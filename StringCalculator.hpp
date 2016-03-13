#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

string head(string text) {
  auto delimiterPosition = text.find(',');
  if (delimiterPosition == string::npos)
    return text;
  return text.substr(0, delimiterPosition);
}

string tail(string text) {
  auto delimiterPosition = text.find(',');
  if (delimiterPosition == string::npos)
    return "";
  return text.substr(delimiterPosition + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  int sum = 0;
  while (!numbers.empty()) {
    sum += toInt(head(numbers));
    numbers = tail(numbers);
  }
  return sum;
}

#endif //STRING_CALCULATOR_HPP
