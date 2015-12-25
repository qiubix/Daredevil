#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

string getHead(const string& numbers, size_t delimiterPosition) {
  return numbers.substr(0, delimiterPosition);
}

string getTail(const string &numbers, size_t delimiterPosition) {
  if (delimiterPosition == string::npos)
    return "";
  return numbers.substr(delimiterPosition + 1);
}

size_t findDelimiter(const string &numbers) {
  return numbers.find(',');
}

int add(string numbers) {
  if (numbers.empty())
    return 0;

  int sum = 0;
  while ( !numbers.empty() ) {
    auto delimiterPosition = findDelimiter(numbers);
    string head = getHead(numbers, delimiterPosition);
    sum += toInt(head);
    numbers = getTail(numbers, delimiterPosition);
  }
  return sum;
}

#endif //STRING_CALCULATOR_HPP
