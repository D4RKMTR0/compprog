#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

long long solve(vector<long long>& s, long long k, long long n) {
  vector<long long> dp(s.size(), LLONG_MAX);

  dp[0] = 0;

  for (int i = 1; i < s.size(); i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j < 0) continue;

      if (dp[i - j] !=  LLONG_MAX) {
        dp[i] = min(dp[i], abs(s[i] - s[i-j]) + dp[i - j]);
      }
    }
  }

  return dp[n-1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, k;
  cin >> n >> k;

  vector<long long> s(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  cout << solve(s, k, n) << '\n';
}
