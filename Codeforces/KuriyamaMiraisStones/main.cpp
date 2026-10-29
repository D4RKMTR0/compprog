#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n;

  vector<long long> v(n);
  vector<long long> p(n);
  vector<long long> s(n);

  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> m;

  p[0] = v[0];
  for(int i = 1; i < n; i++) p[i] = p[i-1] + v[i];

  sort(v.begin(), v.end());
  s[0] = v[0];
  for(int i = 1; i < n; i++) s[i] = s[i-1] + v[i];

  for (int i = 0; i < m; i++) {
    int type;
    long long l, r;
    cin >> type >> l >> r;
    l--;
    r--;

    if (type == 1) {
      cout << (p[r] - (l-1 < 0 ? 0 : p[l-1])) << '\n';
      continue;
    }

    cout << (s[r] - (l-1 < 0 ? 0 : s[l-1])) << '\n';
  }

  return 0;
}
