#include <iostream>
#include <climits>
#include <string>
#include <array>
using namespace std;

int solve(const string& s, const string& t) {
  int si = s.size() - 1;
  int ans = 0;

  while (si >= 0 && s[si] != t[1]) {
    si--;
    ans++;
  }

  if (si < 0) return INT_MAX;

  si--;

  while (si >= 0 && s[si] != t[0]) {
    si--;
    ans++;
  }

  return si < 0 ? INT_MAX : ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  array<string, 4> as = {"00", "25", "50", "75"};

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int ans = INT_MAX;

    for (const string& t : as) {
      ans = std::min(ans, solve(s, t));
    }

    cout << ans << '\n';
  }

  return 0;
}
