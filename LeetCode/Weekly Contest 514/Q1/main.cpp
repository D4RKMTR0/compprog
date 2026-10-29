#include <vector>
#include <algorithm>

class Solution {
public:
  double minPrice(std::vector<int>& prices, std::vector<int>& discounts) {
    std::sort(prices.begin(), prices.end(), std::greater<int>());
    std::sort(discounts.begin(), discounts.end(), std::greater<int>());

    double totalSum = 0;

    int minSize = std::min(prices.size(), discounts.size());
    for (int x = 0; x < minSize; x++) {
      totalSum += prices[x] * (100.0 - discounts[x]) / 100.0;
    }

    for (int x = minSize; x < prices.size(); x++) {
      totalSum += prices[x];
    }
    
    return totalSum;
  }
};
