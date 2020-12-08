#include <iostream>
#include "queue.h"
#include "stack.h"

int main()
{
  TStack<int> a(3);
  TStack<char> b(3);
  a.Put(10);

  char temp = 'a';
  for (int i = 0; i < b.GetSize(); i++)
  {
    b.Put(temp);
    temp++;
  }


  std::cout << a << "\n";
  std::cout << b << "\n";

  return 0;
}
