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

void Stack::push(int data) {
  Node* temp = new Node();

  if (!temp) {
    cout << "Stack overflow" << endl;
  }

  temp->data = data;
  temp->next = this->top;

  this->top = temp;

  this->size++;
}

int Stack::pop() {
  Node* temp = this->top;
  int result = temp->data;

  this->top = temp->next;

  delete temp;
  temp->next = nullptr;

  this->size--;

  return result;
}

bool Stack::isEmpty() { return this->size == 0; }

bool Stack::isFull() { return false; }

int Stack::stackSize() { return this->size; }

void Stack::clearStack() {
  Node* temp = this->top;

  while (temp) {
    this->top = temp->next;
    delete temp;
    temp->next = this->top;
  }

  this->size = 0;
}

void Stack::traverseStack(void (*visit)(int* item)) {
  Node* temp = this->top;

  while (temp) {
    visit(&temp->data);
    temp = temp->next;
  }
}
