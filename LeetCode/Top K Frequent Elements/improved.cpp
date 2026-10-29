#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::priority_queue<std::pair<int, int>> heap;
    std::unordered_map<int, int> counts;
    std::vector<int> result;

    for (const auto& num : nums) {
      counts[num]++;
    }

    for (const auto& entry : counts) {
      heap.push(std::pair(entry.second, entry.first));
    }

    for (int i = 0; i < k; i++) {
      result.push_back(heap.top().second);
      heap.pop();
    }

    return result;
  }
};