#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 * a to the power of b = a^b
 * O(logn) time complexity
 *
 * @param a
 * @param b
 * @return int
 */
int Power(int a, int b)
{
  int result = 1;

  while (b)
  {
    // check if the last bit is set
    if (b & 1)
    {
      result *= a;
    }

    a *= a;

    // right shift b which means divide it to 2
    // b /= 2;
    b >>= 1;
  }

  return result;
}

int main()
{
  int a, b;
  cin >> a >> b;

  cout << Power(a, b) << endl;

  return 0;
}