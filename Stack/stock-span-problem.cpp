#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void StockSpan(int *prices, size_t size, int *span)
{
  stack<int> s;
  s.push(0);
  span[0] = 1;

  for (size_t i = 1; i < size; i++)
  {
    int currentPrice = prices[i];

    // topmost element higher than the current price
    while (!s.empty() && prices[s.top()] <= currentPrice)
    {
      s.pop();
    }

    if (!s.empty())
    {
      // the next largest element is not at the top
      int prevHighest = s.top();
      span[i] = i - prevHighest;
    }
    else
    {
      span[i] = i + 1;
    }

    // push this element into the stack
    s.push(i);
  }
}

int main()
{
  int prices[] = {100, 80, 60, 70, 60, 75, 85};

  int n = sizeof(prices) / sizeof(int);

  int span[10000] = {0};

  StockSpan(prices, n, span);

  for (size_t i = 0; i < n; i++)
  {
    cout << span[i] << " ";
  }
  cout << endl;

  return 0;
}