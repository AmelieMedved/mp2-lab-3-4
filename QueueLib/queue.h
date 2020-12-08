#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int sizeQ; // размер очереди
  T* pQueue; // указатель на массив элементов
  int indQ; // индекс элемента массива, в котором хранится первый элемент очереди
  int end; // индекс элемента массива, в котором хранится последний элемент очереди 
  int count; // количество запомненных в очереди значений
public:
  TQueue(int size = 0); // конструктор по умолчанию
  TQueue(const TQueue<T>& _v);
  ~TQueue();
  TQueue<T>& operator =(const TQueue<T>& _v);

  void Put(T d); // запись элемента в очередь
  T Get(); // извлечь элемент из очереди
 

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueue<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueue<T1> &A);

  int IsEmpty() const; // контроль пустоты очереди
  int IsFull() const; // контроль полноты очереди
  int GetSize(); // вернуть размер очереди
};

template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1> &A) {
  for (int i = A.indQ; i < A.end; i++)
  {
    ostr << A.pQueue[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1> &A) {
  int count;
  istr >> count;
  for (int i = 0; i < count; i++)
  {
    T1 d;
    istr >> d;
    A.Push(d);
  }
  return istr;
}


template<class T>
TQueue<T>::TQueue(int size)
{
  if (size > 0)
  {
    this->sizeQ = size;
    pQueue = new T[sizeQ];
    for (int i = 0; i < sizeQ; i++)
      pQueue[i] = 0;
    this->indQ = 0;
    this->end = 0;
    this->count = 0;
  }
  else
    throw - 1;
}

template<class T>
TQueue<T>::TQueue(const TQueue<T>& _v)
{
  sizeQ = _v.sizeQ;
  indQ = _v.indQ;
  pQueue = new T[sizeQ];
  for (int i = 0; i < sizeQ; i = i++)
    pQueue[i] = _v.pQueue[i];
  indQ = _v.indQ;
  end = _v.end;
  count = _v.count;
}

template <class T>
TQueue<T>::~TQueue()
{
  sizeQ = 0;
  if (pQueue != 0)
    delete [] pQueue;
  pQueue = 0;
}

template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& _v)
{
  if (this == &_v)
    return *this;

  sizeQ = _v.sizeQ;
  delete[] pQueue;
  pQueue = new T[sizeQ];
  for (int i = 0; i < sizeQ; i++)
    pQueue[i] = _v.pQueue[i];
  indQ = _v.indQ;
  end = _v.end;
  count = _v.count;
  return *this;
}

template<class T>
void TQueue<T>::Put(T d)
{
  if (count > sizeQ)
    throw -1;
  if (count == sizeQ)
    end = 0;

  pQueue[end] = d;
  end = (end + 1) % sizeQ;
  count++;
}

template<class T>
T TQueue<T>::Get()
{
  if (count == 0)
    throw - 1;

  T d = pQueue[indQ];
  indQ = (indQ + 1) % sizeQ;
  count--;
  return d;
}

template<class T>
int TQueue<T>::IsEmpty() const
{
  return (indQ == 0);
}

template<class T>
int TQueue<T>::IsFull() const
{
  return (count == sizeQ);
}

template <class T>
int TQueue<T>::GetSize()
{
  return sizeQ;
}


#endif