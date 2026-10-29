#include <vector>
#include <stack>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::stack<int> indexStack;
    std::vector<int> days(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
      if (indexStack.empty()) {
        indexStack.push(i);
        continue;
      }

      while (!indexStack.empty() && temperatures[indexStack.top()] < temperatures[i]) {
        days[indexStack.top()] = i - indexStack.top();
        indexStack.pop();
      }

      indexStack.push(i);
    }

    return days;
  }
};
