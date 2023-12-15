// #define LINKED_STACK

// typedef int StackEntry;

#ifndef LINKED_STACK
#define LINKED_STACK

// struct StackNode<T> {
//   StackEntry entry;
//   StackNode* next;
// };

// struct Stack {
//   StackNode* top;
//   int size;

//   void InitializeStack();
//   void push(StackEntry* ptrStackEntry);
// };

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
