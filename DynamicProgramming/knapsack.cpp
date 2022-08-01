#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 * Recursive Top down approach
 *
 * @param weights weights of each item
 * @param prices price of each item
 * @param N number of items -> size of the weights and prices array
 * @param W capacity
 * @return int
 */
int KnapsackRecursive(int *weights, int *prices, int N, int W)
{
  // base case
  if (W == 0 || N == 0)
  {
    return 0;
  }

  // recursive
  int inc = 0;
  int exc = 0;

  if (weights[N - 1] <= W)
  {
    inc = prices[N - 1] + KnapsackRecursive(weights, prices, N - 1, W - weights[N - 1]);
  }

  exc = KnapsackRecursive(weights, prices, N - 1, W);

  return max(inc, exc);
}

/**
 * @brief
 * Bottom-Up DP approach
 *
 * @param weights
 * @param prices
 * @param N
 * @param W
 * @return int
 */
int KnapsackDP(int *weights, int *prices, int N, int W)
{
  // create 2D array
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  // start iterating from position 1,1
  for (int n = 1; n <= N; n++)
  {
    for (int w = 1; w <= W; w++)
    {
      int include = 0, exclude = 0;

      if (weights[n - 1] <= w)
      {
        include = prices[n - 1] + dp[n - 1][w - weights[n - 1]];
      }

      exclude = dp[n - 1][w];

      dp[n][w] = max(include, exclude);
    }
  }

  return dp[N][W];
}

int main()
{
  int weights[] = {2, 7, 3, 4};
  int prices[] = {5, 20, 20, 10};

  cout << KnapsackRecursive(weights, prices, 4, 11) << endl;
  cout << KnapsackDP(weights, prices, 4, 11) << endl;

  return 0;
}