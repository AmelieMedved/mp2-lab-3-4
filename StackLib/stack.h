#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
  int size; // размер стека
  T* pStack; // указатель на массив элементов
  int indS; // индекс вершины стека

public:
  TStack(int size = 0); // конструктор по умолчанию
  TStack(const TStack<T>& _v); // конструктор копирования
  ~TStack();

  TStack<T>& operator =(const TStack<T>& _v); // оператор сравнения

  void Put(T d); // запись элемента в стек
  T Get(); // извлечь последний записанный элемент стека

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TStack<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TStack<T1> &A);

  int IsEmpty() const; // контроль пустоты стека
  int IsFull() const; // контроль полноты стека
  int GetSize(); // вернуть размер стека
};

template <class T1>
ostream& operator<< (ostream& ostr, const TStack<T1> &A) {
  for (int i = 0; i < A.indS; i++) {
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
TStack<T>::TStack(int size)
{
  if (size > 0)
  {
    this->size = size;
    pStack = new T[size];
    for (int i = 0; i < size; i++)
      pStack[i] = 0;
    this->indS = 0;
  }
  else
    throw - 1;
}

template <class T>
TStack<T>::TStack(const TStack<T>& _v)
{
  size = _v.size;
  indS = _v.indS;
  pStack = new T [size];
  for (int i = 0; i < size;i = i++)
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
TStack<T>& TStack<T>::operator =(const TStack<T>& _v)
{
  if (this == &_v)
    return *this;

  size = _v.size;
  delete[] pStack;
  pStack = new T [size];
  for (int i = 0; i < size; i++)
    pStack[i] = _v.pStack[i];
  indS = _v.indS;
  return *this;
}

template<class T>
void TStack<T>::Put(T d)
{
  if (indS >= size)
    throw - 1;

  pStack[indS] = d;
  indS++;
}

template<class T>
T TStack<T>::Get()
{
  if (indS == 0)
    throw - 1;

  T d = pStack[indS - 1];
  indS--;
  return d;
}

template<class T>
int TStack<T>::IsEmpty() const
{
  return (indS == 0);
}

template<class T>
int TStack<T>::IsFull() const
{
  return (size == indS);
}

template <class T>
int TStack<T>::GetSize()
{
  return size;
}

#endif //_STACK_H_