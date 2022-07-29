#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintRecursively(int i)
{
  if (i == 0)
  {
    cout << i << endl;
    return;
  }

  cout << i << endl;

  PrintRecursively(i - 1);
}

void PrintRecursivelyBacktracking(int i)
{
  if (i == 0)
  {
    cout << i << endl;
    return;
  }

  PrintRecursivelyBacktracking(i - 1);

  cout << i << endl;
}

int main()
{

  PrintRecursively(10);
  cout << "#####" << endl;
  PrintRecursivelyBacktracking(10);

  return 0;
}