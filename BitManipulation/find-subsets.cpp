#include <iostream>
#include <string>
#include <vector>

using namespace std;

void OverlayNumber(char *input, int number)
{
  int j = 0;

  // extract the last bit
  while (number > 0)
  {
    int lastBit = number & 1;

    if (lastBit)
    {
      cout << input[j];
    }

    // move to the next position
    j++;

    number >>= 1;
  }

  cout << endl;
}

void GenerateAllSubsequences(char *input)
{
  int n = strlen(input);

  for (int i = 0; i < (1 << n); i++)
  {
    OverlayNumber(input, i);
  }
}

int main()
{
  char array[10000];
  cin >> array;

  GenerateAllSubsequences(array);

  return 0;
}