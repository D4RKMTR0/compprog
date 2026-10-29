#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      long long num;
      cin >> num;

      sum += num;
    }

    bool wins = (sum % 2 == 1) || ((n*k) % 2 == 0);
    cout << (wins ? "YES" : "NO") << '\n';
  }

  return 0;
}
