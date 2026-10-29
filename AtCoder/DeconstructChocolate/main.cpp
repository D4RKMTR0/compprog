#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long h, w, q;
  cin >> h >> w >> q;

  while (q--) {
    long long type, num;
    cin >> type >> num;

    if (type == 1) {
      if (h >= num + 1) {
        cout << (num * w) << '\n';
        h -= num;
      }
    } else {
      if (w >= num + 1) {
        cout << (num * h) << '\n';
        w -= num;
      }
    }
  }

  return 0;
}
