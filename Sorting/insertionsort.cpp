#include <iostream>
#include <string>
#include <vector>

using namespace std;

void InsertionSort(int *array, int size)
{
  for (int i = 1; i < size; i++)
  {
    int current = array[i];
    int previousIndex = i - 1;

    // compare to the previous one and until we find the correct position
    // loop to find the right index where the current should be inserted
    while (previousIndex >= 0 && array[previousIndex] > current)
    {
      array[previousIndex + 1] = array[previousIndex];
      previousIndex--;
    }

    array[previousIndex + 1] = current;
  }
}

int main()
{
  int array[] = {1, 2, -3, 5, -9, 10, -8, 2, 2, 1, 5, 6, 8, -1, -4, 16};
  int size = sizeof(array) / sizeof(int);

  InsertionSort(array, size);

  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}