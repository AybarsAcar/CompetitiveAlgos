#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintArray(int *array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }

  cout << endl;
}

void BubbleSort(int *array, size_t size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (array[i] > array[j])
      {
        swap(array[i], array[j]);
      }
    }
  }
}

void BubbleSort2(int *array, size_t size)
{
  for (int i = 1; i <= size - 1; i++)
  {
    for (int j = 0; j <= size - 1 - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

void BubbleSortOptimised(int *array, size_t size)
{
  int i, j;
  bool swapped;

  for (i = 0; i < size - 1; i++)
  {
    swapped = false;

    for (j = 0; j < size - 1 - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap(array[j], array[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }
}

int main()
{
  int array[] = {1, 2, -3, 5, -9, 10, -8, 2, 2, 1, 5, 6, 8, -1, -4, 16};
  int size = sizeof(array) / sizeof(int);

  PrintArray(array, size);

  BubbleSortOptimised(array, size);

  return 0;
}