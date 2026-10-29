#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
      if (!(numSet.count(num - 1) > 0)) {
        int current = 1;
        while (true) {
          if (numSet.count(num + current) > 0) {
            current++;
            continue;
          }

          longest = std::max(longest, current);
          break;
        }
      }
    }

    return longest;
  } 
};
