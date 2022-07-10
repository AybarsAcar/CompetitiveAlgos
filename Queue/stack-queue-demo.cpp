#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief
 * Implement a Stack Data structure using 2 queues as the underlying data structure
 * there is no real use case for this question as O(n)
 */
class Stack
{
  queue<int> q1, q2;

public:
  bool IsEmpty()
  {
    return q1.empty() && q2.empty();
  }

  void Push(int data)
  {
    // insert in the non-empty queue
    if (!q1.empty())
    {
      q1.push(data);
    }
    else
    {
      q2.push(data);
    }
  }

  void Pop()
  {
    if (q1.empty())
    {
      // elements presents in q2
      // shift elements from q2 to q1
      while (!q2.empty())
      {
        int front = q2.front();
        q2.pop();

        if (q2.empty())
        {
          break;
        }

        q1.push(front);
      }
    }
    else
    {
      // elements present in q1
      // shift elements from q1 to q2
      while (!q1.empty())
      {
        int front = q1.front();
        q1.pop();

        if (q1.empty())
        {
          break;
        }

        q2.push(front);
      }
    }
  }

  int Top()
  {
    if (q1.empty())
    {
      // elements presents in q2
      // shift elements from q2 to q1
      while (!q2.empty())
      {
        int front = q2.front();
        q2.pop();
        q1.push(front);

        if (q2.empty())
        {
          // return the last element
          return front;
        }
      }
    }
    else
    {
      while (!q1.empty())
      {
        int front = q1.front();
        q1.pop();
        q2.push(front);

        if (q1.empty())
        {
          // return the last element
          return front;
        }
      }
    }
  }
};

int main()
{
  Stack s;

  s.Push(10);
  s.Push(20);
  s.Push(30);
  s.Push(40);
  s.Push(50);

  while (!s.IsEmpty())
  {
    cout << s.Top() << endl;
    s.Pop();
  }

  return 0;
}