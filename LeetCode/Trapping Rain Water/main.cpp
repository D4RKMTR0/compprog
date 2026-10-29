#include <vector>

class Solution {
public:
  int trap(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;
    int trapped = 0;

    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] > leftMax) {
          leftMax = height[left];
        } else if (height[left] < leftMax) {
          trapped += leftMax - height[left];
        }

        left++;
      } else {
        if (height[right] > rightMax) {
          rightMax = height[right];
        } else if (height[right] < rightMax) {
          trapped += rightMax - height[right];
        }

        right--;
      }
    }

    return trapped;
  }
};
