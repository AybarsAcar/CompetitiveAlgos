#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Finds all subsets of the strings
 * it won't change the order of the letters
 *
 * @param input input string
 * @param output output string which is the subset string
 * @param i first index of the input string
 * @param j first index of the output string
 */
void FindAllSubsets(char *input, char *output, int i, int j)
{
  // base case
  if (input[i] == '\0')
  {
    output[j] = '\0'; // to avoid garbage being printed
    cout << output << endl;
    return;
  }

  // recursive case
  // include the ith letter
  output[j] = input[i];
  FindAllSubsets(input, output, i + 1, j + 1);

  // exclude the ith letter
  // we dont increment j so it overwrites the ith letter
  FindAllSubsets(input, output, i + 1, j);
}

/**
 * @brief compares by length first
 * and then the char value of the string
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */
bool compare(string a, string b)
{
  if (a.length() == b.length())
  {
    return a < b;
  }

  return a.length() < b.length();
}

/**
 * @brief Finds all subsets of the strings
 * and stores them in the out vector in sorted in lexographical order
 *
 * @param input
 * @param output
 * @param i
 * @param j
 * @param out
 */
void FindAllSubsets(char *input, char *output, int i, int j, vector<string> &out)
{
  // base case
  if (input[i] == '\0')
  {
    output[j] = '\0'; // to avoid garbage being printed
    string temp(output);
    out.push_back(temp);
    return;
  }

  // recursive case
  // include the ith letter
  output[j] = input[i];
  FindAllSubsets(input, output, i + 1, j + 1, out);

  // exclude the ith letter
  // we dont increment j so it overwrites the ith letter
  FindAllSubsets(input, output, i + 1, j, out);
}

int main()
{
  char input[100];
  char output[100];

  cin >> input;

  vector<string> list;

  FindAllSubsets(input, output, 0, 0, list);

  sort(list.begin(), list.end(), compare);

  for (const auto elem : list)
  {
    cout << elem << ", ";
  }

  cout << endl;
  return 0;
}