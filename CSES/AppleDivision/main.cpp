#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long solve(const vector<long long>& a, long long depth, long long n, long long sum1, long long sum2) {
  if (depth == n) {
    return abs(sum1 - sum2);
  }

  long long left = solve(a, depth+1, n, sum1+a[depth], sum2);
  long long right = solve(a, depth+1, n, sum1, sum2+a[depth]);

  return min(left, right);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> apples(n);

  for (int i = 0; i < n; i++) {
    cin >> apples[i];
  }

  cout << solve(apples, 0, apples.size(), 0, 0);

  return 0;
}
