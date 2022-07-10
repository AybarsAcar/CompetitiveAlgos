#include <iostream>
#include <string>
#include <vector>
#include "list.hpp"

using namespace std;

template <typename T>
void PrintList(const SinglyLinkedList<T> &list)
{
  auto head = list.Begin();

  while (head != nullptr)
  {
    cout << head->GetData() << " -> ";

    head = head->GetNext();
  }
  cout << "NULL" << endl;
}

int main()
{
  SinglyLinkedList<int> list;

  list.PushBack(10);
  list.PushBack(20);
  list.PushFront(5);

  list.Insert(8, 1);

  PrintList(list);

  cout << list.At(2) << endl;

  list.Reverse();

  PrintList(list);

  return 0;
}