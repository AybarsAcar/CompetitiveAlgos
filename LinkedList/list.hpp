template <typename T>
class SinglyLinkedList;

template <typename T>
class Node
{
  // public:
  int data;
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

  T GetData()
  {
    return data;
  }

  Node *GetNext()
  {
    return next;
  }

  friend class SinglyLinkedList<T>;
};

template <typename T>
class SinglyLinkedList
{
  Node<T> *head;
  Node<T> *tail;
  int size;

  int searchHelper(Node<T> *start, T value)
  {
    // base case
    if (start == nullptr)
    {
      return -1;
    }

    if (start->data == value)
    {
      return 0;
    }

    // recurse on the remaining part of the linked list
    int index = searchHelper(start->next, value);

    if (index == -1)
    {
      return -1;
    }

    return index + 1;
  }

public:
  SinglyLinkedList() : head(nullptr), tail(nullptr), size(0){};
  ~SinglyLinkedList();

  T At(const int position);

  Node<T> *Begin() const;

  void Insert(const T data, const int position);

  T PopBack();

  T PopFront();

  void PushBack(const T data);

  void PushFront(const T data);

  void Print() const;

  T Remove(const int position);

  void Reverse();

  /**
   * @brief Searches for a value within the SinglyLinked List
   * it returns the index of the value if found
   * returns -1 if the value does not exist
   *
   * @param value
   * @return int
   */
  int Search(const T value);

  int SearchRecursively(const T value);

  int Size();
};

template <typename T>
T SinglyLinkedList<T>::At(const int position)
{
  auto current = head;
  for (size_t i = 0; i < position; i++)
  {
    current = current->next;
  }

  return current->data;
}

template <typename T>
Node<T> *SinglyLinkedList<T>::Begin() const
{
  return head;
}

template <typename T>
void SinglyLinkedList<T>::Insert(const T data, const int position)
{
  if (position == 0)
  {
    PushFront(data);
    return;
  }

  // find the correct position
  auto temp = head;
  for (size_t i = 0; i < position - 1; i++)
  {
    temp = temp->next;
  }

  // create new node and insert
  auto node = new Node(data);

  node->next = temp->next;
  temp->next = node;

  size++;
}

template <typename T>
T SinglyLinkedList<T>::PopBack()
{
  auto temp = head;

  while (temp->next != tail)
  {
    temp = temp->next;
  }

  int data = temp->data;

  temp->next = nullptr;
  delete tail;
  tail = temp;

  size--;

  return data;
}

template <typename T>
T SinglyLinkedList<T>::PopFront()
{
  auto first = head;

  head = head->next;

  first->next = nullptr;
  auto data = first->data;

  delete first;

  size--;

  return data;
}

template <typename T>
void SinglyLinkedList<T>::PushBack(const T data)
{
  if (head == nullptr)
  {
    // we use dynamic memory allocation because we want the Node to persist
    // after the function call
    auto node = new Node(data);
    head = tail = node;

    size++;

    return;
  }

  auto node = new Node(data);
  tail->next = node;
  tail = node;

  size++;
}

template <typename T>
void SinglyLinkedList<T>::PushFront(const T data)
{
  if (head == nullptr)
  {
    // we use dynamic memory allocation because we want the Node to persist
    // after the function call
    auto node = new Node(data);
    head = tail = node;
    size++;
    return;
  }

  auto node = new Node(data);
  node->next = head;
  head = node;
  size++;
}

template <typename T>
void SinglyLinkedList<T>::Print() const
{
}

template <typename T>
T SinglyLinkedList<T>::Remove(const int position)
{
  if (position == 0)
  {
    return PopFront();
  }

  auto temp = head;

  for (size_t i = 0; i < position - 1 && temp->next != nullptr; i++)
  {
    temp = temp->next;
  }

  auto nodeToRemove = temp->next;
  auto data = nodeToRemove->data;

  temp->next = nodeToRemove->next;
  nodeToRemove->next = nullptr;
  delete nodeToRemove;

  size--;

  return data;
}

template <typename T>
void SinglyLinkedList<T>::Reverse()
{
  auto current = head;
  Node<T> *previous = nullptr;
  Node<T> *next = nullptr;

  while (current != nullptr)
  {
    next = current->next;

    current->next = previous;

    previous = current;
    current = next;
  }

  head = previous;
}

template <typename T>
int SinglyLinkedList<T>::Search(const T value)
{
  auto temp = head;
  int index = 0;

  while (temp != nullptr)
  {
    if (temp->data == value)
    {
      return index;
    }
    index++;
    temp = temp->next;
  }

  return -1;
}

template <typename T>
int SinglyLinkedList<T>::SearchRecursively(const T value)
{
  return searchHelper(head, value);
}

template <typename T>
int SinglyLinkedList<T>::Size()
{
  return size;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  if (head != nullptr)
  {
    delete head;
    head = nullptr;
  }
}
