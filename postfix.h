#ifndef POSTFIX_H
#define POSTFIX_H 1

#include <string>

std::string infixToPostfix(std::string infix);

bool isDigit(char c);

bool precedent(char op, char c);

#endif