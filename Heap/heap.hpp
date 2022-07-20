#include <vector>

using namespace std;

enum HeapType
{
  Min,
  Max
};

class Heap
{
private:
  vector<int> array;
  HeapType type;

private:
  void Heapify(int index);
  bool Compare(int value1, int value2);

public:
  Heap(int size = 10, HeapType type = Min);

  bool IsEmpty() const;

  void Pop();

  void Push(const int data);

  /**
   * @brief
   * returns the minimum element as its a min heap implementation
   *
   * @return int
   */
  int Top() const;
};

Heap::Heap(int size, HeapType type)
{
  this->type = type;

  array.reserve(size + 1);
  array.push_back(-1); // we won't be using index 0, we will start storing from index 1
}

bool Heap::IsEmpty() const
{
  return array.size() == 1;
}

void Heap::Pop()
{
  // swap the first and last element
  int lastIndex = array.size() - 1;
  swap(array[1], array[lastIndex]);

  array.pop_back();

  Heapify(1);
}

void Heap::Push(const int data)
{
  // add to the and of the heap
  array.push_back(data);

  // now heapify (maintain the heap order property)
  int index = array.size() - 1;
  int parentIndex = index / 2;

  while (index > 1 && Compare(array[index], array[parentIndex]))
  {
    swap(array[index], array[parentIndex]);
    index = parentIndex;
    parentIndex = parentIndex / 2;
  }
}

int Heap::Top() const
{
  return array[1];
}

bool Heap::Compare(int value1, int value2)
{
  switch (this->type)
  {
  case Min:
    return value1 < value2;
    break;

  case Max:
    return value1 > value2;
    break;

  default:
    break;
  }
}

void Heap::Heapify(int index)
{
  int left = 2 * index;
  int right = 2 * index + 1;

  int minIdx = index;

  if (left < array.size() && Compare(array[left], array[index]))
  {
    minIdx = left;
  }

  if (right < array.size() && Compare(array[right], array[minIdx]))
  {
    minIdx = right;
  }

  if (minIdx != index)
  {
    swap(array[index], array[minIdx]);
    Heapify(minIdx);
  }
}