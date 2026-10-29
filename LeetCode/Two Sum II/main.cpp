#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      if (numbers[left] + numbers[right] > target) {
        right--;
        continue;
      } else if (numbers[left] + numbers[right] < target) {
        left++;
        continue;
      }

      return {left + 1, right + 1};
    }

    return {};
  }
};
