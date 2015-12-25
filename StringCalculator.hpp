#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

int toInt(const string& text) {
  return atoi(text.c_str());
}

bool hasOnlyOneNumber(const string& numbers) {
  return numbers.find(',') == string::npos;
}

string getHead(const string& numbers, size_t delimiterPosition) {
  return numbers.substr(0, delimiterPosition);
}

string getTail(const string &numbers, size_t delimiterPosition) {
  if (delimiterPosition == string::npos)
    return "";
  return numbers.substr(delimiterPosition + 1);
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  else if (hasOnlyOneNumber(numbers))
    return toInt(numbers);
  else {
    int sum = 0;
    while ( !numbers.empty() ) {
      size_t delimiterPosition = numbers.find(',');
      string head = getHead(numbers, delimiterPosition);
      sum += toInt(head);
      numbers = getTail(numbers, delimiterPosition);
    }
    return sum;
  }
}

#endif //STRING_CALCULATOR_HPP
