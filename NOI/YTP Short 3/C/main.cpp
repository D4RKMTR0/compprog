#include <algorithm>
#include <iostream>
using namespace std;

string shift(string& s, long long sft) {
  if (sft % s.size() == 0) return s;

  string otpt;
  otpt.resize(s.size());

  for (size_t i = 0; i < s.size(); i++) {
    otpt[(i - sft + s.size()) % s.size()] = s[i];
  }

  return otpt;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    string ss, st;
    cin >> ss >> st;

    long long highest = 0;

    for (int i = 0; i < n; i++) {
      string sfted = shift(ss, i);
      long long matched = 0;

      for (int i = 0; i < n; i++) {
        if (sfted[i] == st[i]) {
          matched++;
        }
      }

      highest = max(highest, matched);
    }

    cout << (highest >= n ? n : highest+1) << '\n';
  }

  return 0;
}
