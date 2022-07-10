#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void InsertAtBottom(stack<int> &stack, int data)
{
  // base
  if (stack.empty())
  {
    stack.push(data);
    return;
  }

  int temp = stack.top();
  stack.pop();

  InsertAtBottom(stack, data);

  // push back the temp variable when backtracking
  stack.push(temp);
}

void Reverse(stack<int> &stack)
{
  if (stack.empty())
  {
    return;
  }

  int temp = stack.top();
  stack.pop();

  Reverse(stack);

  InsertAtBottom(stack, temp);
}

int main()
{

  stack<int> s;

  for (int i = 1; i <= 6; i++)
  {
    s.push(i);
  }

  InsertAtBottom(s, 100);

  Reverse(s);

  // print
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}