#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long solve(int n) {
  if (n == 0) return 2;
  if (n == 1) return 1;

  vector<long long> dp(n + 1, LLONG_MAX);

  dp[0] = 2;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  cout << solve(n) << '\n';

  return 0;
}
