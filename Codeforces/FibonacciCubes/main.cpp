#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long fib(long long n) {
  vector<long long> dp(n+1, 0);

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

string solve(long long lrg, long long sml) {
  long long w, l, h;
  cin >> w >> l >> h;

  if ((w >= lrg && l >= lrg && h >= lrg + sml) ||
      (w >= lrg && l >= lrg + sml && h >= lrg) ||
      (w >= lrg + sml && l >= lrg && h >= lrg)
  ) {
    return "1";
  }

  return "0";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n, m;
    cin >> n >> m;

    string s;

    long long lrg = fib(n);
    long long sml = fib(n-1);

    for (int i = 0 ; i < m; i++) {
      s += solve(lrg, sml);
    }

    cout << s << '\n';
  }

  return 0;
}
