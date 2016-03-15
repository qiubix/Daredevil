#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

using namespace std;

class NegativesAreNotAllowed : public exception {
public:
  NegativesAreNotAllowed(const string& negativesList) : negatives(negativesList) {}
  virtual const char* what() const throw() {
    auto message = "Negatives are not allowed: " + negatives;
    return message.c_str();
  }

private:
  string negatives;
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

int nextNumber(string numbers) {
  return toInt(head(numbers));
}

int add(string numbers) {
  if (numbers.empty())
    return 0;
  if (hasComment(numbers)) {
    addNewDelimiter(numbers);
    numbers = removeComment(numbers);
  }
  int sum = 0;
  vector<int> negatives;
  while (!numbers.empty()) {
    auto next = nextNumber(numbers);
    if (next < 0) {
      negatives.push_back(next);
    }
    sum += next;
    numbers = tail(numbers);
  }
  if ( !negatives.empty() ) {
    string negativesList = "";
    for (auto i : negatives) {
      negativesList += to_string(i);
      if (i != negatives.back()) {
        negativesList += ",";
      }
    }
    throw NegativesAreNotAllowed(negativesList);
  }
  delimiters = {",", "\n"};
  return sum;
}

#endif //STRING_CALCULATOR_HPP
