#ifndef LINKED_STACK
#define LINKED_STACK

typedef char StackEntry;

struct Node {
  StackEntry data;
  Node* next;

  Node();
};

struct Stack {
  Node* top;
  int size;

  Stack();
  ~Stack();
  void push(StackEntry data);
  StackEntry pop();
  StackEntry stackTop();
  bool isEmpty();
  bool isFull();
  int stackSize();
  void clearStack();
  void traverseStack(void (*visit)(StackEntry* item));
};

#endif
