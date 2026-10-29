#include <iostream>
#include <vector>
using namespace std;

long long solve(vector<long long>& cns, long long c, long long x) {
  if (c > x) return 0;
  if (c == x) return 1;

  long long currSum = 0;

  for (const auto& cn : cns) {
    currSum = (currSum + solve(cns, c + cn, x)) % (1000000007);
  }

  return currSum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n, x;
  cin >> n >> x;

  vector<long long> cns(n);

  for (int i = 0; i < n; i++) {
    cin >> cns[i];
  }



  return 0;
}
