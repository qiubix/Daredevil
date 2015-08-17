String calculator:
http://osherove.com/tdd-kata-1/

int add(string numbers);

- Method can take 0, 1 or 2 numbers and will return their sum
    - return 0 for an empty string
    - Comma is a delimiter between numbers
- Handle unknown amount of numbers
- Allows new line as a delimiter
- Support different delimiters
- Calling add with negative number will throw an exception "negatives are not allowed" and the negative that was passed. Show all negative arguments in the exception message.
