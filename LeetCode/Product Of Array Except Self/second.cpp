#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products(nums.size(), 1);

    int left = 1;
    for (int i = 0; i < nums.size(); i++) {
      products[i] = left;
      left *= nums[i];
    }

    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      products[i] *= right;
      right *= nums[i];
    }

    return products;
  }
};
