#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int length;
  T* x;
  int ind;
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
  for (int i = A.ind; i < A.end; i++)
  {
    ostr << A.x[i] << endl;
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
    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
      x[i] = 0;
    this->ind = 0;
    this->end = 0;
    this->count = 0;
  }
  else
    throw - 1;
}

template <class T>
TQueue<T>::~TQueue()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}

template <class T>
TQueue<T>& TQueue<T>::operator =(TQueue<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  delete[] x;
  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  ind = _v.ind;
  end = _v.end;
  count = _v.count;
  return *this;
}

template<class T>
inline void TQueue<T>::Push(T d)
{
  if (count >= length)
    throw - 1;

  x[end] = d;
  end = (end + 1) % length;
}

template<class T>
inline T TQueue<T>::Get()
{
  if (count == 0)
    throw - 1;

  T d = x[ind];
  ind = (ind + 1) % length;
  return d;
}

template <class T>
int TQueue<T>::Length()
{
  return length;
}


#endif