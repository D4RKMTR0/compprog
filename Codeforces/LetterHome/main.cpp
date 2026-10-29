#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<int> nums;
  vector<int> visitedNums;
  int stepCount = 0;

  while (t--) {
    int n, s;
    cin >> n >> s;

    while (n--) {
      int num;
      cin >> num;

      nums.push_back(num);
    }

    visitedNums.push_back(nums[n - 1]);

    int pos = s - 1;
    bool leftDirection = pos > n / 2 || nums[pos] == nums.back();
    int boundary = leftDirection ? 0 : n;
    while ((leftDirection ? pos <= boundary : pos > boundary) || visitedNums.size() < nums.size()) {
      if (leftDirection)
    }

    if (pos == boundary) {
      
    }
  }

  return 0;
}
