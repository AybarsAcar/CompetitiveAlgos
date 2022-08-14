#include <iostream>
#include <string>
#include <vector>

using namespace std;

char DigitToChar(int digit)
{
  return digit + '0';
}

int CharToDigit(char input)
{
  return input - '0';
}

string LargeSum(string n1, string n2)
{
  // make sure n2 is larger
  if (n1.length() > n2.length())
  {
    swap(n1, n2);
  }

  string result = "";

  // reverse
  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  int carry = 0;

  // add digits upto n1.length() as it is the shorter one
  for (int i = 0; i < n1.length(); i++)
  {
    int digit1 = CharToDigit(n1[i]);
    int digit2 = CharToDigit(n2[i]);

    int sum = digit1 + digit2 + carry;

    int outputDigit = sum % 10;
    carry = sum / 10;

    result.push_back(DigitToChar(outputDigit));
  }

  // as n2 is larger loop over the remaining digits of n2
  for (int i = n1.length(); i < n2.length(); i++)
  {
    int digit2 = CharToDigit(n2[i]);
    int sum = digit2 + carry;

    int outputDigit = sum % 10;
    carry = sum / 10;

    result.push_back(DigitToChar(outputDigit));
  }

  // if there is a carry still remaining
  result.push_back(DigitToChar(carry));

  reverse(result.begin(), result.end());

  return result;
}

int main()
{
  string a, b;

  cin >> a >> b;

  string result = LargeSum(a, b);

  cout << result << endl;

  return 0;
}