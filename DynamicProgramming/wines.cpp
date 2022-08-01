#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 * Top Down DP approach
 *
 * @param dp
 * @param prices
 * @param left
 * @param right
 * @param year
 * @return int
 */
int Wines(int (*dp)[10], int *prices, int left, int right, int year)
{
  // base case
  if (left > right)
    return 0;

  // check if a state is already computed
  if (dp[left][right] != 0)
  {
    // we assume it is computed already if the value is 0
    return dp[left][right];
  }

  // recursive
  int pickLeftFirst = year * prices[left] + Wines(dp, prices, left + 1, right, year + 1);
  int pickRightFirst = year * prices[right] + Wines(dp, prices, left, right - 1, year + 1);

  dp[left][right] = max(pickLeftFirst, pickRightFirst);

  return dp[left][right];
}

int WinesBottomUp(int *prices, int size)
{
  vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

  for (int i = size - 1; i >= 0; i--)
  {
    // bottom row to top row
    for (int j = 0; j < size; j++)
    {
      // fill the cells for i < j which is the upper half of the matrix
      // we go row by row
      if (i <= j)
      {
        int year = size - (j - i);
        int pickLeft = prices[i] * year + dp[i + 1][j];
        int pickRight = prices[j] * year + dp[i][j - 1];

        dp[i][j] = max(pickLeft, pickRight);
      }
    }
  }

  return dp[0][size - 1];
}

int main()
{
  int winePrices[] = {2, 3, 5, 1, 4};
  int dp[10][10] = {0};

  cout << Wines(dp, winePrices, 0, 4, 1) << endl;

  cout << WinesBottomUp(winePrices, 5) << endl;

  return 0;
}