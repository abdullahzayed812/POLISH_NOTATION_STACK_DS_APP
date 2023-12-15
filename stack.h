#ifndef LINKED_STACK
#define LINKED_STACK

struct Node {
  int data;
  Node* next;

  Node();
};

struct Stack {
  Node* top;
  int size;

  Stack();
  void push(int data);
  int pop();
  bool isEmpty();
  bool isFull();
  int stackSize();
  void clearStack();
  void traverseStack(void (*visit)(int* item));
};

#endif
