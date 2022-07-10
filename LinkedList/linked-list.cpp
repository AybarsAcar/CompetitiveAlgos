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

  SinglyLinkedList<string> list2;

  list2.PushBack("Hello");

  list2.PushBack("World");

  PrintList(list2);

  list2.Reverse();

  cout << list2.Search("Hello") << endl;

  PrintList(list2);

  return 0;
}