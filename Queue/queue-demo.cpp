#include <iostream>
#include <string>
#include <vector>
#include "queue.hpp"

using namespace std;

int main()
{
  Queue<int> queue;

  queue.Append(10);
  queue.Append(40);
  queue.Append(20);
  queue.Append(60);

  while (!queue.IsEmpty())
  {
    cout << queue.Front() << " ";
    queue.Enqueue();
  }
  cout << endl;

  return 0;
}