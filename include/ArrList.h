#pragma once

template <class T>
class TArrList
{
protected:
  size_t size;
  T* arr;
  int* index;
  size_t count;
  int startIndex;
  int endIndex;
  int freeIndex;
public:
  TArrList(size_t _size = 1);
  TArrList(const TArrList& _arr);
  TArrList(const TArrList&& _arr);
  ~TArrList();

  void PushStart(T _data);
  void PushEnd(T _data);
  void Push(T _data, size_t i);

  T GetStart();
  T GetEnd();
  T Get(size_t i);
  T GetSize();

  void DelStart();
  void DelEnd();
  void Del(size_t i);

  bool isFull();
  bool isEmpty();

  int FindIndex(size_t i);

  TArrList& operator=(const TArrList& v);
};

template<class T>
inline TArrList<T>::TArrList(size_t _size)
{
  if (_size == 0)
    throw "error — _size = 0";

  size = _size;

  arr = new T[size];

  index = new int[size];

  count = 0;

  startIndex = -1;

  endIndex = -1;

  freeIndex = 0;

  for (size_t i = 0; i < size; i++)
    index[i] = -2;
}

template<class T>
inline TArrList<T>::TArrList(const TArrList& _arr)
{
  size = _arr.size;

  arr = new T[size];

  index = new int[size];

  count = _arr.count;

  startIndex = _arr.startIndex;

  endIndex = _arr.endIndex;

  freeIndex = _arr.freeIndex;

  for (size_t i = 0; i < size; i++)
  {
    index[i] = _arr.index[i];

    arr[i] = _arr.arr[i];
  }
}

template<class T>
inline TArrList<T>::TArrList(const TArrList&& _arr)
{
  size = _arr.size;

  arr = _arr.arr;

  index = _arr.index;

  count = _arr.count;

  startIndex = _arr.startIndex;

  endIndex = _arr.endIndex;

  freeIndex = _arr.freeIndex;

  _arr.size = 0;

  _arr.arr = nullptr;

  _arr.index = nullptr;

  _arr.count = 0;

  _arr.startIndex = 0;

  _arr.endIndex = 0;

  _arr.freeIndex = 0;
}

template<class T>
inline TArrList<T>::~TArrList()
{
  if (arr != nullptr)
  {
    delete[] arr;

    delete[] index;

    arr = nullptr;

    index = nullptr;
  }
}

template<class T>
inline void TArrList<T>::PushStart(T _data)
{
  if (isFull())
    throw "arr is full error";

  arr[freeIndex] = _data;

  index[freeIndex] = startIndex;

  startIndex = freeIndex;

  if (endIndex == -1)
    endIndex = freeIndex;

  count++;

  freeIndex++;
}

template<class T>
inline void TArrList<T>::PushEnd(T _data)
{
  if (isFull())
    throw "arr is full error";

  arr[freeIndex] = _data;

  index[freeIndex] = -1;

  index[endIndex] = freeIndex;

  endIndex = freeIndex;

  if (startIndex == -1)
    startIndex = freeIndex;

  count++;

  freeIndex++;
}

template<class T>
inline void TArrList<T>::Push(T _data, size_t i)
{
  if (isFull())
    throw "arr is full error";

  if ((i >= count) || (i < 0))
    throw "error bad i";

  arr[freeIndex] = _data;

  if (startIndex == -1)
  {
    startIndex = freeIndex;

    index[freeIndex] = -1;
  }
  else
  {
    size_t j = FindIndex(i);

    index[freeIndex] = index[j];

    index[j] = freeIndex;
  }

  if (endIndex == -1)
    endIndex = freeIndex;

  count++;

  freeIndex++;
}

template<class T>
inline T TArrList<T>::GetStart()
{
  if (isEmpty())
    throw "List is Empty";

  return arr[startIndex];
}

template<class T>
inline T TArrList<T>::GetEnd()
{
  if (isEmpty())
    throw "List is Empty";

  return arr[endIndex];
}

template<class T>
inline T TArrList<T>::Get(size_t i)
{
  if (isEmpty())
    throw "List is Empty";

  size_t j = FindIndex(i);

  return arr[j];
}

template<class T>
inline T TArrList<T>::GetSize()
{
  return count;
}

template<class T>
inline void TArrList<T>::DelStart()
{
  if (isEmpty())
    throw "List is Empty";

  int tmp = startIndex;

  startIndex = index[startIndex];

  index[tmp] = -2;

  count--;

  if (count == 0)
  {
    startIndex = -1;

    endIndex = -1;
  }
}

template<class T>
inline void TArrList<T>::DelEnd()
{
  if (isEmpty())
    throw "List is Empty";

  int tmp = endIndex;

  size_t j = startIndex;

  for (; index[j] != endIndex; j = index[j]);

  endIndex = j;

  index[j] = -1;

  index[tmp] = -2;

  count--;

  if (count == 0)
  {
    startIndex = -1;

    endIndex = -1;
  }
}

template<class T>
inline void TArrList<T>::Del(size_t i)
{
  if (isEmpty())
    throw "List is Empty";

  if (count == 1)
  {
    index[startIndex] = -2;

    startIndex = -1;

    endIndex = -1;
  }

  size_t j = startIndex;

  size_t p = -1; 

  int k = 0;

  for (; k < count; j = index[j], k++)
  {
    if (k == i)
      break;

    p = j;
  }

  index[p] = index[j];

  index[j] = -2;

  count--;
}

template<class T>
inline bool TArrList<T>::isFull()
{
  return (count >= size);
}

template<class T>
inline bool TArrList<T>::isEmpty()
{
  return (count <= 0);
}

template<class T>
inline int TArrList<T>::FindIndex(size_t i)
{
  size_t j = startIndex;

  int k = 0;

  for (; k < count; j = index[j], k++)
    if (k == i)
      break;

  return j;
}

template<class T>
inline TArrList<T>& TArrList<T>::operator=(const TArrList<T>& v)
{
  if (this != &v)
  {
    if (index != nullptr && arr != nullptr)
    {
      delete[] arr;

      delete[] index;
    }

    count = v.count;

    startIndex = v.startIndex;

    endIndex = v.endIndex;

    freeIndex = v.freeIndex;

    size = v.size;

    arr = new T[size];

    index = new int[size];

    for (size_t i = 0; i < size; i++)
    {
      arr[i] = v.arr[i];

      index[i] = v.index[i];
    }
  }
  else
  {
    return *this;
  }
}
