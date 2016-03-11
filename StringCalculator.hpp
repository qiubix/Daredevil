#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

bool hasOnlyOneNumber(string text) {
  return text.find(',') == string::npos;
}

string head(string text) {
  auto delimiterPosition = text.find(',');
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
  else if (hasOnlyOneNumber(numbers))
    return toInt(numbers);
  else {
    int sum = 0;
    while (!numbers.empty()) {
      sum += toInt(head(numbers));
      numbers = tail(numbers);
    }
    return sum;
  }
}

#endif //STRING_CALCULATOR_HPP
