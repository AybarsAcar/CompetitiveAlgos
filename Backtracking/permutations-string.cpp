#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintPermutations(string input, int i = 0)
{
  // base case
  if (i == input.length() - 1)
  {
    cout << input << endl;
    return;
  }

  for (int j = 0; j < input.length(); j++)
  {
    swap(input[i], input[j]);

    PrintPermutations(input, i + 1);

    // swap back when backtracking to keep the original string
    swap(input[i], input[j]);
  }
}

int main()
{
  string input;
  cin >> input;

  PrintPermutations(input);

  return 0;
}