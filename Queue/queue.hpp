template <typename T>
class Queue
{
  T *array;
  int size;
  int maxSize;

  int front; // front index
  int back;  // back index

public:
  Queue(int defaultSize = 5);

  void Append(const T data);

  void Enqueue();

  T Front() const;

  bool IsEmpty() const;

  bool IsFull() const;
};

template <typename T>
Queue<T>::Queue(int defaultSize)
{
  maxSize = defaultSize;
  array = new T[maxSize];
  size = 0;
  front = 0;
  back = maxSize - 1; // because insertion will happen at back + 1;
}

template <typename T>
void Queue<T>::Append(const T data)
{
  if (!IsFull())
  {
    // increment the back index and wrap
    back = (back + 1) % maxSize;
    array[back] = data;
    size++;
  }
}

template <typename T>
void Queue<T>::Enqueue()
{
  if (!IsEmpty())
  {
    // take the front pointer forward
    front = (front + 1) % maxSize;
    size--;
  }
}

template <typename T>
T Queue<T>::Front() const
{
  return array[front];
}

template <typename T>
bool Queue<T>::IsEmpty() const
{
  return size == 0;
}

template <typename T>
bool Queue<T>::IsFull() const
{
  return size == maxSize;
}
