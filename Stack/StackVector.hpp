#include <vector>

using namespace std;

template <typename T>
class StackDA
{
  vector<T> array;

public:
  bool IsEmpty();

  T Peek() const;

  void Pop();

  void Push(const T data);
};

template <typename T>
bool StackDA<T>::IsEmpty()
{
  return array.size() == 0;
}

template <typename T>
T StackDA<T>::Peek() const
{
  return array.back();
}

template <typename T>
void StackDA<T>::Pop()
{
  array.pop_back();
}

template <typename T>
void StackDA<T>::Push(const T data)
{
  array.push_back(data);
}