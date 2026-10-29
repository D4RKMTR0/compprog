#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string s;
  cin >> s;

  int highest = -1;
  int cnt = 1;
  char last = ' ';

  for (const char& c : s) {
    if (last == ' ' || !last) {
      last = c;
      continue;
    }

    if (c == last) {
      cnt++;
    } else {
      highest = max(highest, cnt);
      cnt = 1;
    }

    last = c;
  }

  highest = max(highest, cnt);

  cout << highest << '\n';

  return 0;
}
