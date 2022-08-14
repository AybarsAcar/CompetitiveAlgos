#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Multiply(int *a, int no, int &size)
{
  int carry = 0;

  for (int i = 0; i < size; i++)
  {
    int product = a[i] * no + carry;

    a[i] = product % 10;
    carry = product / 10;
  }

  // handle the remaining carry
  while (carry)
  {
    a[size] = carry % 10;

    carry = carry / 10;

    // increement the value of size
    size++;
  }
}

void LargeFactorial(int n)
{
  int result[1000];

  // initialise 1 factorial as 1
  result[0] = 1;
  int size = 1;

  for (int i = 2; i <= n; i++)
  {
    Multiply(result, i, size);
  }

  // print the result in reverse order
  for (int i = size - 1; i >= 0; i--)
  {
    cout << result[i];
  }
  cout << endl;
}

int main()
{
  int n;
  cin >> n;

  LargeFactorial(n);

  return 0;
}