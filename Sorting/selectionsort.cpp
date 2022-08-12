#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SelectionSort(int *array, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int minElementPos = i;

    // to find the minimum element of the array to the right of the current position i
    for (int j = i; j < size; j++)
    {
      if (array[j] < array[minElementPos])
      {
        minElementPos = j;
      }
    }

    // swap once the minimum is found
    swap(array[i], array[minElementPos]);
  }
}

int main()
{
  int array[] = {1, 2, -3, 5, -9, 10, -8, 2, 2, 1, 5, 6, 8, -1, -4, 16};
  int size = sizeof(array) / sizeof(int);

  SelectionSort(array, size);

  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}