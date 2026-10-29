#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long solve(vector<long long>& cns, vector<long long>& mem, long long total, long long target) {
  if (total == target) return 0;
  if (total > target) return LLONG_MAX;
  if (mem[total] != -1) return mem[total];

  long long minc = LLONG_MAX;

  for (int i = 0; i < cns.size(); i++) {
    long long res = solve(cns, mem, total + cns[i], target);
    if (res != LLONG_MAX) {
      minc = min(minc, res + 1);
    }
  }

  return mem[total] = minc;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n, x;
  cin >> n >> x;

  vector<long long> cns(n);
  vector<long long> mem(x + 1, -1);

  for (int i = 0; i < n; i++) {
    cin >> cns[i];
  }

  cout << solve(cns, mem, 0, x) << '\n';

  return 0;
}
