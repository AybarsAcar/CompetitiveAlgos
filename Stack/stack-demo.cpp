#include <iostream>
#include <string>
#include <vector>
#include "StackLinkedList.hpp"

using namespace std;

int main()
{
  Stack<string> stack;

  stack.Push("Hello");

  stack.Push("World");

  while (!stack.IsEmpty())
  {
    cout << stack.Peek() << endl;
    stack.Pop();
  }

  return 0;
}