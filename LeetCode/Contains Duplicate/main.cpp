#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

auto speedup = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> memory;
    memory.reserve(nums.size()); 

    for (int num : nums) {
      if (memory.count(num)) {
        return true;
      }
      memory.insert(num);
    }
    return false;
  }
};