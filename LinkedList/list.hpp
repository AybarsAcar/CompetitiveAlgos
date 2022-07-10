class SinglyLinkedList;

class Node
{
  // public:
  int data;
  Node *next;

public:
  Node(int data) : data(data), next(nullptr) {}

  ~Node()
  {
    if (next != nullptr)
    {
      delete next;
    }
  }

  int GetData()
  {
    return data;
  }

  Node *GetNext()
  {
    return next;
  }

  friend class SinglyLinkedList;
};

class SinglyLinkedList
{
  Node *head;
  Node *tail;
  int size;

  int searchHelper(Node *start, int value)
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

  int At(const int position);

  Node *Begin() const;

  void Insert(const int data, const int position);

  int PopBack();

  int PopFront();

  void PushBack(const int data);

  void PushFront(const int data);

  void Print() const;

  int Remove(const int position);

  void Reverse();

  /**
   * @brief Searches for a value within the SinglyLinked List
   * it returns the index of the value if found
   * returns -1 if the value does not exist
   *
   * @param value
   * @return int
   */
  int Search(const int value);

  int SearchRecursively(const int value);

  int Size();
};

int SinglyLinkedList::At(const int position)
{
  auto current = head;
  for (size_t i = 0; i < position; i++)
  {
    current = current->next;
  }

  return current->data;
}

Node *SinglyLinkedList::Begin() const
{
  return head;
}

void SinglyLinkedList::Insert(const int data, const int position)
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

int SinglyLinkedList::PopBack()
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

int SinglyLinkedList::PopFront()
{
  auto first = head;

  head = head->next;

  first->next = nullptr;
  auto data = first->data;

  delete first;

  size--;

  return data;
}

void SinglyLinkedList::PushBack(const int data)
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

void SinglyLinkedList::PushFront(const int data)
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

void SinglyLinkedList::Print() const
{
}

int SinglyLinkedList::Remove(const int position)
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

void SinglyLinkedList::Reverse()
{
  auto current = head;
  Node *previous = nullptr;
  Node *next = nullptr;

  while (current != nullptr)
  {
    next = current->next;

    current->next = previous;

    previous = current;
    current = next;
  }

  head = previous;
}

int SinglyLinkedList::Search(const int value)
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

int SinglyLinkedList::SearchRecursively(const int value)
{
  return searchHelper(head, value);
}

int SinglyLinkedList::Size()
{
  return size;
}

SinglyLinkedList::~SinglyLinkedList()
{
  if (head != nullptr)
  {
    delete head;
    head = nullptr;
  }
}
