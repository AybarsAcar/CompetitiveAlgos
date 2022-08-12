#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 *
 * @param distances 2D distances grapsh
 * @param setOfCitis list of cities in bit representation
 * @param city current city
 * @param numberOfCities
 * @return int
 */
int tsp(vector<vector<int>> distances, int setOfCitis, int city, int numberOfCities)
{
  // base case
  // we have covered all the cities
  if (setOfCitis == (1 << numberOfCities) - 1)
  {
    // return the cost of from the current city to the starting city
    return distances[city][0];
  }

  int answer = INT_MAX;

  // recursively try all possible options
  for (int i = 0; i < numberOfCities; i++)
  {
    // check if the city is visited or not by checking ith bit is set or not
    if ((setOfCitis & (1 << i)) == 0)
    {
      // this city is not visited
      int subProblem = distances[city][i] + tsp(distances, setOfCitis | (1 << i), i, numberOfCities);

      answer = min(answer, subProblem);
    }
  }

  return answer;
}

int tspWithDP(vector<vector<int>> distances, int setOfCitis, int city, int numberOfCities, vector<vector<int>> &dp)
{
  // base case
  // we have covered all the cities
  if (setOfCitis == (1 << numberOfCities) - 1)
  {
    // return the cost of from the current city to the starting city
    return distances[city][0];
  }

  // if its already visited return the answer
  if (dp[setOfCitis][city] != -1)
  {
    return dp[setOfCitis][city];
  }

  int answer = INT_MAX;

  // recursively try all possible options
  for (int i = 0; i < numberOfCities; i++)
  {
    // check if the city is visited or not by checking ith bit is set or not
    if ((setOfCitis & (1 << i)) == 0)
    {
      // this city is not visited
      int subProblem = distances[city][i] + tsp(distances, setOfCitis | (1 << i), i, numberOfCities);

      answer = min(answer, subProblem);
    }
  }

  // memorise the answer
  dp[setOfCitis][city] = answer;

  return answer;
}

int main()
{

  vector<vector<int>> dist = {
      {0, 20, 42, 25},
      {20, 0, 30, 34},
      {42, 30, 0, 10},
      {25, 34, 10, 0}};

  int n = 4; // number of cities

  vector<vector<int>> dp(1 << n, vector<int>(n, -1));

  cout << tsp(dist, 1, 0, n) << endl;

  cout << tspWithDP(dist, 1, 0, n, dp) << endl;

  return 0;
}