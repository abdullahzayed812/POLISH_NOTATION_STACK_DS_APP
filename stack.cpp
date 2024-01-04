#include "stack.h"

#include <iostream>

using std::cout;
using std::endl;

Node::Node() {
  this->data = -1;
  this->next = nullptr;
}

Stack::Stack() {
  this->top = nullptr;
  this->size = 0;
}

Stack::~Stack() {
  this->clearStack();
  this->top = nullptr;
}

void Stack::push(StackEntry data) {
  Node* newNode = new Node();

  if (!newNode) {
    cout << "Stack overflow" << endl;
  }

  newNode->data = data;
  newNode->next = this->top;

  this->top = newNode;

  this->size++;
}

StackEntry Stack::pop() {
  Node* temp = this->top;
  StackEntry result = temp->data;

  this->top = temp->next;

  delete temp;
  temp->next = nullptr;

  this->size--;

  return result;
}

StackEntry Stack::stackTop() { return this->top->data; }

bool Stack::isEmpty() { return this->size == 0; }

bool Stack::isFull() { return false; }

int Stack::stackSize() { return this->size; }

void Stack::clearStack() {
  Node* temp = this->top;

  while (temp) {
    this->top = temp->next;
    delete temp;
    temp->next = nullptr;
    temp = this->top;
  }

  this->size = 0;
  std::cout << "\nStack is clear.\n";
}

void Stack::traverseStack(void (*visit)(StackEntry* item)) {
  Node* temp = this->top;

  while (temp) {
    visit(&temp->data);
    temp = temp->next;
  }
}
