#include <iomanip>
#include <iostream>

#include "postfix.h"
#include "stack.h"

int main() {
  std::string postfix = infixToPostfix("1+2*3$4/5-6");
  std::cout << postfix << "\n";

  std::cout << evaluatePostfix(postfix) << "\n";

  return 0;
}