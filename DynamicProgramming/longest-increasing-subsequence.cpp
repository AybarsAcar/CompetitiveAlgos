#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LongestIncreasingSubsequence(const vector<int> &array)
{
  int n = array.size();
  vector<int> dp(n, 1);

  int lis = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (array[i] > array[j])
      {
        dp[i] = max(dp[i], 1 + dp[j]);

        lis = max(lis, dp[i]);
      }
    }
  }

  return lis;
}

int main()
{
  vector<int> array = {50, 4, 10, 8, 30, 100};

  cout << LongestIncreasingSubsequence(array) << endl;

  return 0;
}