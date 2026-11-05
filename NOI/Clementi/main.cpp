#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    float n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<pair<unsigned long long, unsigned long long>> h(n);

    for (int i = 0; i < n; i++) {
      unsigned long long x, y;
      cin >> x >> y;

      h[i].first = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
      h[i].second = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    }

    sort(h.begin(), h.end());

    vector<unsigned long long> s(n + 1, 0);

    for (int i = n - 1; i >= 0; i++) {
      s[i] = max(s[i+1], h[i].second);
    }

    unsigned long long mt = ~0ULL;

    for (int i = 0; i <= n; i++) {
      mt = min(mt, (i > 0 ? h[i].first : 0) + s[i]);
    }

    cout << fixed << setprecision(9) << mt << '\n';
  }

  return 0;
}
