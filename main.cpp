#include <iostream>

#include "stack.h"

using std::cout;

void printItem(int* item) { cout << *item << "\n"; }

int main() {
  Stack* myStack = new Stack();

  myStack->push(10);
  myStack->push(20);
  myStack->push(30);
  myStack->push(40);

  myStack->traverseStack(printItem);

  int first = myStack->pop();
  int second = myStack->pop();

  cout << "First item is :" << first << " Second item is : " << second << "\n ";

  return 0;
}