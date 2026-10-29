#include <iostream>
#include <string>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string s;
  cin >> s;

  char common = ((s[0] == s[1] || s[0] == s[2]) ? s[0] : s[1]);

  for (size_t i = 0; i < s.size(); i++) {
    if (common != s[i]) {
      cout << (i+1) << '\n';
      break;
    }
  }

  return 0;
}
