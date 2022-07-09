#include <iostream>
#include <vector>

using namespace std;

void PrintArray(int *array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
}

/**
 * @brief Fills the array in consecutive values
 *
 * @param array
 * @param i
 * @param n
 * @param val
 */
void FillArray(int *array, int i, int n, int val)
{
  // base case
  if (i == n)
  {
    // print our array
    PrintArray(array, n);
    return;
  }

  // recursive
  array[i] = val;

  FillArray(array, i + 1, n, val + 1);

  // backtracking step where we change the array for each call stack
  // as we are popping off the function from the stack
  array[i] = -1 * array[i];
}

void PrintVec(const vector<int> &vec)
{
  for (auto elem : vec)
  {
    cout << elem << ", ";
  }
}

void FillArray(vector<int> &vec, int i, int n, int val)
{
  if (i == n)
  {
    PrintVec(vec);
    return;
  }

  // recursive
  vec[i] = val;

  FillArray(vec, i + 1, n, val + 1);

  // backtracking step where we change the array for each call stack
  // as we are popping off the function from the stack
  vec[i] = -1 * vec[i];
}

int main()
{
  int arr[100] = {0};
  int n;

  cin >> n;

  FillArray(arr, 0, n, 1);
  cout << endl;
  PrintArray(arr, n);

  cout << endl;

  vector<int> vec(n, 0);
  FillArray(vec, 0, n, 1);
  cout << endl;
  PrintVec(vec);

  cout << endl;

  return 0;
}