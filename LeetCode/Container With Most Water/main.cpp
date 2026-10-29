#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int largestArea = 0;

    for (int i = 0; i < height.size() - 1; i++) {
      for (int j = i + 1; j < height.size(); j++) {
        int area = std::min(height[i], height[j]) * (j - i);
        largestArea = std::max(largestArea, area);
      }
    }
    return largestArea;
  }
};