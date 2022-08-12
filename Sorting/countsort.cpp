#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CountSort(int *array, int size)
{
  // find the largest element
  int largestElement = INT_MIN;

  for (int i = 0; i < size; i++)
  {
    largestElement = max(largestElement, array[i]);
  }

  // initialise the counts array
  vector<int> counts(largestElement + 1, 0);

  // update the counts array
  for (int i = 0; i < size; i++)
  {
    counts[array[i]]++;
  }

  // write to the original array
  int arrayIndex = 0;

  for (int i = 0; i <= largestElement; i++)
  {
    while (counts[i] > 0)
    {
      array[arrayIndex] = i;
      counts[i]--;
      arrayIndex++;
    }
  }
}

int main()
{
  int array[] = {1, 4, 1, 10, 2, 16, 1, 8};
  auto size = sizeof(array) / sizeof(int);

  CountSort(array, size);

  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}