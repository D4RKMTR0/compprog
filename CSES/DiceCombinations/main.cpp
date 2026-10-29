#include <iostream>
#include <vector>
using namespace std;

long long solve(int target) {
  vector<long long> dp(target + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) dp[i] = (dp[i] + dp[i-j]) % 1000000007;
    }
  }

  return dp[target];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  cout << solve(n) << '\n';

  return 0;
}
