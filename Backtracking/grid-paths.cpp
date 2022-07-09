#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief returns the number of ways we can go from the initial cell (i,j)
 * to the end of the grid cell (m,n) also the size of the grid
 * Time complexity is O(2^(m+n))
 *
 * @param i
 * @param j
 * @param m
 * @param n
 * @return int
 */
int CountPaths(int i, int j, int m, int n)
{
  if (i == m - 1 && j == n - 1)
  {
    return 1;
  }

  // corner case don't make a call outside of grid
  if (j >= n || i >= m)
  {
    return 0;
  }

  return CountPaths(i + 1, j, m, n) + CountPaths(i, j + 1, m, n);
}

/**
 * @brief return ((m-1) + (n-1))! / (m-1)! (n-1)!
 *
 * @param i
 * @param j
 * @param m
 * @param n
 * @return int
 */
int CountPathsWithPermutations(int i, int j, int m, int n)
{
  return 1;
}

int main()
{
  int m, n;

  cin >> m >> n;

  cout << CountPaths(0, 0, m, n) << endl;

  return 0;
}