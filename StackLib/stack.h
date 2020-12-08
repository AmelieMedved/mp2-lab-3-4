#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
  int size;
  T* pStack;
  int inS;

public:
  TStack(int size = 0);
  TStack(TStack<T>& _v);
  ~TStack();

  TStack<T>& operator =(TStack<T>& _v);

  void Push(T d);
  T Get();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TStack<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TStack<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TStack<T1> &A) {
  for (int i = 0; i < A.inS; i++) {
    ostr << A.pStack[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TStack<T1> &A) {
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
inline TStack<T>::TStack(int size)
{
  if (size > 0)
  {
    this->size = size;
    pStack = new T[size];
    for (int i = 0; i < size; i++)
      pStack[i] = 0;
    this->inS = 0;
  }
  else
    throw - 1;
}

template <class T>
TStack<T>::TStack(TStack<T>& _v)
{
  size = _v.size;
  inS = _v.inS;
  pStack = new T [size];
  for (int i = 0; i < size;i = i + 1)
    pStack[i] = _v.pStack[i];
}
template <class T>
TStack<T>::~TStack()
{
  size = 0;
  if (pStack != 0)
    delete[] pStack;
  else
    throw - 1;
  pStack = 0;
}

template <class T>
TStack<T>& TStack<T>::operator =(TStack<T>& _v)
{
  if (this == &_v)
    return *this;

  size = _v.size;
  delete[] pStack;
  pStack = new T [size];
  for (int i = 0; i < size; i++)
    pStack[i] = _v.pStack[i];
  inS = _v.inS;
  return *this;
}

template<class T>
inline void TStack<T>::Push(T d)
{
  if (inS >= size)
    throw - 1;

  pStack[inS] = d;
  inS++;
}

template<class T>
inline T TStack<T>::Get()
{
  if (inS == 0)
    throw - 1;

  T d= pStack[inS - 1];
  inS--;
  return d;
}

template <class T>
int TStack<T>::Length()
{
  return size;
}

#endif //_STACK_H_