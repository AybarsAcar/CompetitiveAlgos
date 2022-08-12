#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Merge(vector<int> &input, int start, int end)
{
  int i = start;
  int mid = (start + end) / 2;
  int j = mid + 1;

  vector<int> temp;

  while (i <= mid && j <= end)
  {
    if (input[i] < input[j])
    {
      temp.push_back(input[i]);
      i++;
    }
    else
    {
      temp.push_back(input[j]);
      j++;
    }
  }

  // copy bakc the remaining elements from the first array
  while (i <= mid)
  {
    temp.push_back(input[i++]);
  }

  // copy back the remaining elements from the second array
  while (j <= end)
  {
    temp.push_back(input[j++]);
  }

  // copy back the elements from our temp array to original array
  int tempIndex = 0;
  for (int i = start; i <= end; i++)
  {
    input[i] = temp[tempIndex++];
  }
}

void MergeSort(vector<int> &input, int start, int end)
{
  // base case
  if (start >= end)
    return;

  int mid = (start + end) / 2;

  // merge sort left portion
  MergeSort(input, start, mid);

  // merge sort right portion
  MergeSort(input, mid + 1, end);

  // merge them
  Merge(input, start, end);
}

int main()
{
  vector<int> array = {1, 2, 53, 1, 42, 12, 312, 3, -83, 1, 3, 253, 24, 90, 89, 8, -1};

  MergeSort(array, 0, array.size());

  for (auto value : array)
  {
    cout << value << " ";
  }
  cout << endl;

  return 0;
}