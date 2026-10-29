#include <iostream>
using namespace std;

int blocks(long long n, long long m, long long x, long long y) {
  if ((x == 1 || x == n) && (y == 1 || y == m)) {
    return 2;
  } else if (x == 1 || x == n || y == 1 || y == m) {
    return 3;
  } else {
    return 4;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    cout << min(blocks(n, m, x1, y1), blocks(n, m, x2, y2)) << '\n';
  }

  return 0;
}
