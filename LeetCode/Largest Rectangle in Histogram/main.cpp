#include <vector>
#include <stack>

class Solution {
public:
  int largestRectangleArea(std::vector<int>& heights) {
    std::stack<int> prevHeights;
    int largestArea = 0;

    for (int i = 0; i < heights.size(); i++) {
      while (!  prevHeights.empty() && heights[prevHeights.top()] > heights[i]) {
        int h = heights[prevHeights.top()];
        prevHeights.pop();

        int width = prevHeights.empty() ? i : (i - prevHeights.top() - 1);
        largestArea = std::max(largestArea, h * width);
      }

      prevHeights.push(i);
    }

    return largestArea;
  }
};
