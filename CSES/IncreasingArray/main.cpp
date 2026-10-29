#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> nums(n);

  long long total = 0;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  for (int i = 1; i < n; i++) {
    if (nums[i-1] > nums[i]) {
      long long r = nums[i-1] - nums[i];
      total += r;
      nums[i] += r;
    }
  }

  cout << total << '\n';

  return 0;
}
