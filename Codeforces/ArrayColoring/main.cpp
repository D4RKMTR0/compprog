#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      sum += num;
    }

    cout << (sum % 2 == 0 ? "YES" : "NO") << '\n';
  }

  return 0;
}
