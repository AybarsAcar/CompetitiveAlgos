#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 * goal is to find the minimum amount of coins required to reach M
 * this is the Bottom up approach
 *
 * input -> coins = [1, 3, 7, 10] and M = 15
 * output -> 3 where we used 2 x 7 coin and a 1 coin
 *
 * @param coins array of coins with values
 * @param M target money
 * @return int
 */
int CoinChange(vector<int> coins, int M)
{
  vector<int> dp(M + 1, 0);
  dp[0] = 0;

  for (int i = 1; i <= M; i++)
  {
    dp[i] = INT_MAX;

    for (int coin : coins)
    {
      if (i - coin >= 0 && dp[i - coin] != INT_MAX)
      {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return dp[M] == INT_MAX ? -1 : dp[M];
}

int main()
{
  vector<int> coins = {1, 3, 7, 10};
  int m = 15;

  cout << CoinChange(coins, m) << endl;

  return 0;
}