#ifndef POSTFIX_H
#define POSTFIX_H 1

#include <string>

std::string infixToPostfix(std::string infix);

bool isDigit(char c);

bool precedent(char op, char c);

double evaluate(double op1, double op2, char aOperator);

double evaluatePostfix(std::string postfix);

#endif