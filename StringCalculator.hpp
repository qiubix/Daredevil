#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

static vector<string> delimiters = { ",", "\n" };

size_t findDelimiter(const string& text) {
  for ( auto delimiter : delimiters ) {
    auto position = text.find(delimiter);
    if ( position != string::npos )
      return position;
  }
  return text.length();
}

string head(const string& text) {
  auto position = findDelimiter(text);
  return text.substr(0, position);
}

string tail(const string& text) {
  auto position = findDelimiter(text);
  if ( position == text.length() )
    return "";
  return text.substr(position + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  if (numbers.substr(0,2) == "//") {
    auto position = findDelimiter(numbers);
    auto newDelimiter = numbers.substr(2,1);
    delimiters.push_back(newDelimiter);
    numbers.erase(numbers.begin(), numbers.begin() + position + 1);
  }
  int sum = 0;
  while ( numbers != "" ) {
    sum += toInt(head(numbers));
    numbers = tail(numbers);
  }
  return sum;
}

#endif //STRING_CALCULATOR_HPP
