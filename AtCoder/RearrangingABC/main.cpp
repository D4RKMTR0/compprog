#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a = 0, b = 0, c = 0;
  string s;
  cin >> s;

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a++;
    }

    if (s[i] == 'B') {
      b++;
    }

    if (s[i] == 'C') {
      c++;
    }
  }

  cout << (a == 1 && b == 1 && c == 1 ? "Yes" : "No") << '\n';

  return 0;
}
