#include <iomanip>
#include <iostream>

#include "postfix.h"
#include "stack.h"

int main() {
  std::string postfix = infixToPostfix("1+2+3*5$1/2-3");
  std::cout << postfix << "\n";

  return 0;
}