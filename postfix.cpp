#include "postfix.h"

#include <string>

#include "stack.h"

bool isDigit(char c) { return c >= '0' && c <= '9'; }

bool precedent(char op1, char op2) {
  if (op1 == '$') {
    return true;
  } else if (op1 == '*' || op1 == '/') {
    return (op2 != '$');
  } else if (op1 == '+' || op1 == '-') {
    return (op2 != '$' && op2 != '*' && op2 != '/');
  }

  return false;
}

std::string infixToPostfix(std::string infix) {
  Stack* operatorsStack = new Stack();
  std::string postfix;
  char topOperator;

  for (char currentChar : infix) {
    if (isdigit(currentChar)) {
      postfix += currentChar;
    } else {
      if (!operatorsStack->isEmpty()) {
        topOperator = operatorsStack->stackTop();

        while (!operatorsStack->isEmpty() && precedent(topOperator, currentChar)) {
          postfix += topOperator;

          if (!operatorsStack->isEmpty()) {
            topOperator = operatorsStack->stackTop();
          }
        }
      } else {
        operatorsStack->push(currentChar);
      }
    }
  }

  while (!operatorsStack->isEmpty()) {
    postfix += operatorsStack->pop();
  }

  return postfix;
}