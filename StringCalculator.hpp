#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

class NegativesAreNotAllowed : public exception {
};

int toInt(string text) {
  return atoi(text.c_str());
}

vector<string> delimiters = {",", "\n"};

size_t findDelimiter(string text) {
  for (auto delimiter : delimiters) {
    auto position = text.find(delimiter);
    if (position != string::npos)
      return position;
  }
  return text.length();
}

bool hasComment(const string &text) {
  return text.substr(0, 2) == "//";
}

void addNewDelimiter(const string &text) {
  auto newDelimiter = text.substr(2, 1);
  delimiters.push_back(newDelimiter);
}

string &removeComment(string &text) {
  auto position = findDelimiter(text);
  text = text.substr(position + 1);
  return text;
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

bool isNextNumberNegative(const string &text) {
  return text[0] == '-';
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  if (hasComment(numbers)) {
    addNewDelimiter(numbers);
    numbers = removeComment(numbers);
  }
  int sum = 0;
  while (!numbers.empty()) {
    if (isNextNumberNegative(numbers))
      throw NegativesAreNotAllowed();
    sum += toInt(head(numbers));
    numbers = tail(numbers);
  }
  delimiters = {",", "\n"};
  return sum;
}

#endif //STRING_CALCULATOR_HPP
