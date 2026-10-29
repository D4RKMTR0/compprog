#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int largestArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
      largestArea = std::max(largestArea, (right - left) * std::min(height[left], height[right]));

      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }
    
    return largestArea;
  }
};