#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(string text) {
  return atoi(text.c_str());
}

const vector<string> delimiters = {",", "\n"};

size_t findDelimiter(string text) {
  for (auto delimiter : delimiters) {
    auto position = text.find(delimiter);
    if (position != string::npos)
      return position;
  }
  return text.length();
}

string head(string text) {
  auto position = findDelimiter(text);
  return text.substr(0, position);
}

string tail(string text) {
  auto position = findDelimiter(text);
  if (position == text.length()) {
    return "";
  }
  else {
    return text.substr(position + 1);
  }
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
