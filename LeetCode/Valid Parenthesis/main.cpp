#include <string>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> parenthesisStack;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        parenthesisStack.push(c);
      } else if (c == ')' || c == ']' || c == '}') {
        if (parenthesisStack.empty()) {
          return false;
        }

        if (c == ')') {
          if (parenthesisStack.top() == '(') {
            parenthesisStack.pop();
            continue;
          }

          return false;
        }

        if (c == ']') {
          if (parenthesisStack.top() == '[') {
            parenthesisStack.pop();
            continue;
          }

          return false;
        }

        if (c == '}') {
          if (parenthesisStack.top() == '{') {
            parenthesisStack.pop();
            continue;
          }

          return false;
        }
      }
    }

    return parenthesisStack.empty();
  }
};
