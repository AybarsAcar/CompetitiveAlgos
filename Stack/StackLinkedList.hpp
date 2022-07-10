template <typename T>
class Stack;

template <typename T>
class Node
{
  T data;
  Node<T> *next;

public:
  Node(T data) : data(data), next(nullptr) {}

  ~Node()
  {
    if (next != nullptr)
    {
      delete next;
    }
  }

  friend class Stack<T>;
};

template <typename T>
class Stack
{
  Node<T> *head;

public:
  Stack() : head(nullptr) {}
  ~Stack()
  {
    if (head != nullptr)
    {
      delete head;
      head = nullptr;
    }
  }

  bool IsEmpty();

  T Peek() const;

  void Pop();

  void Push(const T data);
};

template <typename T>
bool Stack<T>::IsEmpty()
{
  return head == nullptr;
}

template <typename T>
T Stack<T>::Peek() const
{
  return head->data;
}

template <typename T>
void Stack<T>::Pop()
{
  if (head != nullptr)
  {
    auto temp = head;

    head = head->next;

    temp->next = nullptr;
    delete temp;
  }
}

template <typename T>
void Stack<T>::Push(const T data)
{
  auto node = new Node<T>(data);

  node->next = head;
  head = node;
}