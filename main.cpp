#include <iomanip>
#include <iostream>

#include "stack.h"

using std::boolalpha;
using std::cout;

void printItem(int* item) { cout << *item << "\n"; }

int main() {
  Stack* myStack = new Stack();

  myStack->push(10);
  myStack->push(20);
  myStack->push(30);
  myStack->push(40);

  myStack->clearStack();

  return 0;
}