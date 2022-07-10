template <typename T>
class Stack;

template <typename T>
class Node
{
  T data;
  Node<T> *next;

public:
  Node(T data) : data(data), next(nullptr) {}
};
