#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
  string key;
  T value;
  Node *next;

  Node(string key, T value) : key(key), value(value), next(nullptr) {}

  ~Node()
  {
    if (next != nullptr)
    {
      delete next;
    }
  }
};

template <typename T>
class HashTable
{
  Node<T> **table;
  int size;     // total entries that have been inserted so fac
  int capacity; // size of the table

private:
  int Hash(string key);

  void ReHash();

public:
  HashTable(int defaultSize = 7);

  T *Get(string key);

  void Insert(string key, T value);

  void PrintKeys();

  void Remove(string key);

  int Size() const;

  T &operator[](string const &key);
};

template <typename T>
HashTable<T>::HashTable(int defaultSize)
{
  size = 0;
  capacity = defaultSize;

  // allocate array
  table = new Node<T> *[capacity];

  // each bucket will contain some garbage so make them NULL
  // as it is the head of the linked list
  for (int i = 0; i < capacity; i++)
  {
    table[i] = nullptr;
  }
}

template <typename T>
T *HashTable<T>::Get(string key)
{
  int idx = Hash(key);

  Node<T> *current = table[idx];

  while (current != nullptr)
  {
    if (current->key == key)
    {
      return &current->value;
    }

    current = current->next;
  }

  return nullptr;
}

template <typename T>
void HashTable<T>::Insert(string key, T value)
{
  int idx = Hash(key);

  Node<T> *node = new Node<T>(key, value);

  // insertion at head of the linked list
  node->next = table[idx];
  table[idx] = node;

  size++;

  // rehashing if load factor is reached
  float loadFactor = size / capacity;
  if (loadFactor > 0.7)
  {
    // double the size of the backing array
    // and rehash and insert all the existing elements
    ReHash();
  }
}

template <typename T>
void HashTable<T>::PrintKeys()
{
  // iterate over all the buckets
  for (int i = 0; i < capacity; i++)
  {
    // itirate over the linked list for each bucket
    Node<T> *current = table[i];
    while (current != nullptr)
    {
      cout << current->key << ", ";
      current = current->next;
    }
  }
  cout << endl;
}

template <typename T>
int HashTable<T>::Size() const
{
  return size;
}

template <typename T>
void HashTable<T>::Remove(string key)
{
  // find the bucket id
  int idx = Hash(key);

  Node<T> *current = table[idx];
  Node<T> *previous = NULL;

  // iterate over the linked list and delete the matching value
  while (current != NULL)
  {
    if (current->key == key)
    {
      if (previous == NULL)
      {
        table[idx] = current->next;
      }
      else
      {
        previous->next = current->next;
      }

      current->next = nullptr;

      delete current;
      return;
    }

    previous = current;
    current = current->next;
  }
}

template <typename T>
T &HashTable<T>::operator[](string const &key)
{
  // if key is not founf then create anew node and return
  // otherwise return the existing node

  auto valueAddress = Get(key);

  if (valueAddress == nullptr)
  {
    // create the object and insert
    T object;
    Insert(key, object);

    // we don't know the object value we will be assigning from outside
    valueAddress = Get(key);
  }

  return *valueAddress;
}

template <typename T>
int HashTable<T>::Hash(string key)
{
  int idx = 0;
  int power = 1;

  for (auto c : key)
  {
    idx = (idx + c * power) % capacity;
    power = (power * 29) % capacity;
  }

  return idx;
}

template <typename T>
void HashTable<T>::ReHash()
{
  // save the pointer to the old table and do insertions in the new table
  Node<T> **oldTable = table;

  // update table capacity
  auto oldCapacity = capacity;
  size = 0;                    // because we will call insert
  capacity = 2 * capacity + 1; // to keep it prime

  // point the backing array to a new table with the updated capacity
  table = new Node<T> *[capacity];

  for (int i = 0; i < capacity; i++)
  {
    table[i] = nullptr;
  }

  // copy elements from the old table to new table
  for (int i = 0; i < oldCapacity; i++)
  {
    // create a temp pointer to the linked list
    Node<T> *temp = oldTable[i];

    while (temp != nullptr)
    {
      auto key = temp->key;
      T value = temp->value;

      // insert new node into new hash table
      Insert(key, value);

      temp = temp->next;
    }

    // destroy the ith linked list
    if (oldTable[i] != nullptr)
    {
      delete oldTable[i];
    }
  }

  // destroy the old table
  delete[] oldTable;
}