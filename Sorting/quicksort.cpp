#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief returns the correct index in the sorted array for the pivot
 *
 * @param array
 * @param start
 * @param end
 * @return int
 */
int Partition(vector<int> &array, int start, int end)
{
  // select the last element as the pivot
  int pivot = array[end];
  int i = start - 1;

  for (int j = start; j < end; j++)
  {
    if (array[j] < pivot)
    {
      i++;
      swap(array[i], array[j]);
    }
  }

  // insert pivot in its correct location
  swap(array[i + 1], array[end]);

  return i + 1;
}

void QuickSort(vector<int> &array, int start, int end)
{
  // base case
  if (start >= end)
  {
    return;
  }

  // recursive case
  // partition
  int pivot = Partition(array, start, end);

  // quicksort the left part
  QuickSort(array, start, pivot - 1);

  // quicksort the right part
  QuickSort(array, pivot + 1, end);
}

int main()
{
  vector<int> array{10, 5, 2, 0, -3, 6, 1, 7, -8, 6};

  QuickSort(array, 0, array.size() - 1);

  for (auto elem : array)
  {
    cout << elem << ", ";
  }

  cout << endl;

  return 0;
}
