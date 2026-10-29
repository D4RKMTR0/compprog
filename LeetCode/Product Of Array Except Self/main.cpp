#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products;
    std::vector<int> left(nums.size());
    left[0] = 1;
    std::vector<int> right(nums.size());
    right[nums.size() - 1] = 1;

    for (int i = 1; i < nums.size(); i++) {
      left[i] = left[i-1] * nums[i-1];
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
      right[i] = right[i+1] * nums[i+1];
    }

    for (int i = 0; i < nums.size(); i++) {
      products.push_back(left[i] * right[i]);
    }

    return products;
  }
};