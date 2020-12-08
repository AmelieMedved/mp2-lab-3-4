#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int sizeQ;
  T* pQueue;
  int indQ;
  int end;
  int count;
public:
  TQueue(int size = 0);
  ~TQueue();
  TQueue<T>& operator =(TQueue<T>& _v);

  void Push(T d);
  T Get();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueue<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueue<T1> &A);

  int Length();
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
inline TQueue<T>::TQueue(int size)
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

template <class T>
TQueue<T>::~TQueue()
{
  sizeQ = 0;
  if (pQueue != 0)
    delete [] pQueue;
  pQueue = 0;
}

template <class T>
TQueue<T>& TQueue<T>::operator =(TQueue<T>& _v)
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
inline void TQueue<T>::Push(T d)
{
  if (count >= sizeQ)
    throw - 1;

  pQueue[end] = d;
  end = (end + 1) % sizeQ;
}

template<class T>
inline T TQueue<T>::Get()
{
  if (count == 0)
    throw - 1;

  T d = pQueue[indQ];
  indQ = (indQ + 1) % sizeQ;
  return d;
}

template <class T>
int TQueue<T>::Length()
{
  return sizeQ;
}


#endif