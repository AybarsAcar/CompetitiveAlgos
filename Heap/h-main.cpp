#include <iostream>
#include <string>
#include <vector>

#include "heap.hpp"

using namespace std;

int main()
{

  Heap heap(10, Max);

  heap.Push(20);
  heap.Push(30);
  heap.Push(492);
  heap.Push(8);
  heap.Push(49);

  cout << heap.Top() << endl;

  return 0;
}