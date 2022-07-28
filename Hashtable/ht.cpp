#include <iostream>
#include <string>
#include <vector>

#include "hashtable.hpp"

using namespace std;

int main()
{
  HashTable<int> table;

  table.Insert("Burger", 14);
  table.Insert("Cake", 20);
  table.Insert("Banana Cake", 4);
  table.Insert("Orange Juice", 7);
  table.Insert("Pizza", 28);
  table.Insert("Steak", 45);

  table.PrintKeys();

  cout << table.Size() << endl;

  auto value = table.Get("Cake");

  if (value != nullptr)
  {
    cout << "Memory address of Value for Key Cake is " << value << endl;
    cout << "Value for Key Cake is " << *value << endl;
  }
  else
  {
    cout << "Key does not exist" << endl;
  }

  table.Remove("Orange Juice");

  table["Toastie"] = 8;

  table.PrintKeys();

  cout << "Toastie Value " << table["Toastie"] << endl;

  table["Toastie"] = 12;
  cout << "Updated Toastie Value " << table["Toastie"] << endl;

  return 0;
}