#include <vector>
#include <string>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> nums;

    for (auto& token : tokens) {
      if (token != "+" && token != "-" && token != "*" && token != "/") {
        nums.push(std::stoi(token));
        continue;
      }

      int b = nums.top();
      nums.pop();
      int a = nums.top();
      nums.pop();

      switch (token[0]) {
        case '+':
          nums.push(a + b);
          break;

        case '-':
          nums.push(a - b);
          break;

        case '*':
          nums.push(a * b);
          break;

        case '/':
          nums.push(a / b);
          break;
      }
    }

    return nums.top();
  }
};
