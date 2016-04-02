#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

vector<char> delimiters = {',', '\n'};

int toInt(string text) {
  return atoi(text.c_str());
}

size_t findDelimiter(string text) {
  for (auto delimiter : delimiters) {
    auto position = text.find(delimiter);
    if (position != string::npos)
      return position;
  }
  return string::npos;
}

string head(string text) {
  auto delimiterPosition = findDelimiter(text);
  return text.substr(0, delimiterPosition);
}

string tail(string text) {
  auto delimiterPosition = findDelimiter(text);
  if (delimiterPosition == string::npos)
    return "";
  return text.substr(delimiterPosition + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
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
