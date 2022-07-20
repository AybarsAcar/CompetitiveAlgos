#ifndef DynamicArray_h
#define DynamicArray_h

/// This is a dynamic size array implementation
/// similar to vector from the STL or ArrayList from Java Standard Library
template <typename T>
class DynamicArray
{

  T *array;     // backing array
  int size;     // how many elements are stored
  int capacity; // max size of the backing array

public:
  DynamicArray(int capacity = 1);

  /// appends element to the end of the dynamic array
  void Append(const T value);

  /// removes the last element
  void PopBack();

  bool IsEmpty() const;

  T Front() const;
  T Back() const;
  T At(const int index) const;

  int Size() const;
  int Capacity() const;

  T operator[](const int index) const;
};

template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
  this->size = 0;
  this->capacity = capacity;
  this->array = new T[capacity];
}

template <typename T>
void DynamicArray<T>::Append(const T value)
{

  // when the array is full
  if (size == capacity)
  {
    // create a new array, copy the values and delete the old array
    T *oldArray = array;

    // create new array with double the capacity
    capacity = 2 * capacity;
    array = new T[capacity];

    // copy the elements
    for (int i = 0; i < capacity / 2; i++)
    {
      array[i] = oldArray[i];
    }

    // delete old array
    delete[] oldArray;
  }

  // append the new element to the end
  array[size] = value;
  size++;
}

template <typename T>
void DynamicArray<T>::PopBack()
{
  if (size > 0)
  {
    size--;
  }
}

template <typename T>
bool DynamicArray<T>::IsEmpty() const
{
  return size == 0;
}

template <typename T>
T DynamicArray<T>::Front() const
{
  return array[0];
}

template <typename T>
T DynamicArray<T>::Back() const
{
  return array[size - 1];
}

template <typename T>
T DynamicArray<T>::At(const int index) const
{
  return array[index];
}

template <typename T>
int DynamicArray<T>::Size() const
{
  return size;
}

template <typename T>
int DynamicArray<T>::Capacity() const
{
  return capacity;
}

template <typename T>
T DynamicArray<T>::operator[](const int index) const
{
  return array[index];
}

#endif /* DynamicArray_h */