#include <iostream>
#include <utility>
#include <numeric>
#include <set>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  set<pair<long long, long long>> distinct;

  while (n--) {
    long long a, b;
    cin >> a >> b;

    long long divisor = gcd(a, b);
    long long simpA = a / divisor;
    long long simpB = b / divisor;

    distinct.insert({simpA, simpB});
  }

  cout << distinct.size() << '\n';

  return 0;
}
