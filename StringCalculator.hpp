#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

const vector<string> delimiters = {",", "\n"};

string head(string text) {
  for (auto delimiter : delimiters) {
    auto position = text.find(delimiter);
    if (position != string::npos)
      return text.substr(0, position);
  }
  return text;
}

string tail(string text) {
  for (auto delimiter : delimiters) {
    auto position = text.find(delimiter);
    if (position != string::npos)
      return text.substr(position + 1);
  }
  return "";
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
