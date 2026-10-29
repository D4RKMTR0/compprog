#include <utility>
#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, int>> carData;
    for (int i = 0; i < position.size(); i++) {
      carData.push_back({position[i], speed[i]});
    }
    std::sort(carData.begin(), carData.end());

    std::stack<double> travelTimes;

    for (int i = carData.size() - 1; i >= 0; i--) {
      double time = static_cast<double>(target - carData[i].first) / carData[i].second;

      if (travelTimes.empty() || time > travelTimes.top()) {
        travelTimes.push(time);
      }
    }

    return travelTimes.size();
  }
};
