#include "postfix.h"

#include <cmath>
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

double evaluate(double op1, double op2, char aOperator) {
  switch (aOperator) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    case '$':
      return std::pow(op1, op2);
    default:
      return -1;
  }
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
          postfix += operatorsStack->pop();

          if (!operatorsStack->isEmpty()) {
            topOperator = operatorsStack->stackTop();
          }
        }
      }

      operatorsStack->push(currentChar);
    }
  }

  while (!operatorsStack->isEmpty()) {
    postfix += operatorsStack->pop();
  }

  return postfix;
}

double evaluatePostfix(std::string postfix) {
  Stack* _stack = new Stack();
  double value;

  for (char currentChar : postfix) {
    if (isDigit(currentChar)) {
      _stack->push((double)(currentChar - '0'));
    } else {
      double op1 = _stack->pop();
      double op2 = _stack->pop();

      value = evaluate(op1, op2, currentChar);
      _stack->push(value);
    }
  }

  return _stack->pop();
}