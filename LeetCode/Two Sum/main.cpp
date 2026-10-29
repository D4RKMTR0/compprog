#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> memory;

    for (int x = 0; x < nums.size(); x++) {
      int currentNum = nums[x];
      int complement = target - currentNum;

      if (memory.count(complement)) {
        
        return {memory[complement], x};
      }

      memory[currentNum] = x;
    }

    return {};
  }
};