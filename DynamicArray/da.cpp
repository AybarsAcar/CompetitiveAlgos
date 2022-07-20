#include <iostream>
#include <string>
#include <vector>

#include "dynamic-array.hpp"

using namespace std;

int main()
{

  DynamicArray<int> a;

  a.Append(10);

  cout << a[0] << endl;

  return 0;
}