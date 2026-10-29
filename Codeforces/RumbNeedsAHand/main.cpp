#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    bool possible = true;
    vector<long long> nums;
    vector<long long> selected;
    vector<long long> selectedIndexes;

    for (size_t i = 0; i < n; i++) {
      long long num;
      cin >> num;

      nums.push_back(num);
    }

    for (size_t i = 0; i < n; i++) {
      int currentNum = nums[i];
      if (currentNum != i+1) {
        selected.push_back(currentNum);
        selectedIndexes.push_back(i);
        continue;
      }
    }

    std::reverse(selected.begin(), selected.end());

    for (size_t i = 0; i < selectedIndexes.size(); i++) {
      nums[selectedIndexes[i]] = selected[i];
    }

    for (size_t i = 0; i < n; i++) {
      if (nums[i] != i+1) {
        possible = false;
        break;
      }
    }

    cout << (possible ? "Yes" : "No") << '\n';
  }

  return 0;
}
