#include <iostream>
#include <array>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  array<array<char, 3>, 3> t;
  array<array<char, 3>, 3> l;
  array<array<char, 3>, 3> f;
  array<array<char, 3>, 3> r;
  array<array<char, 3>, 3> bk;
  array<array<char, 3>, 3> bm;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char ch;
      cin >> ch;

      t[i][j] = ch;
    }
  }


  return 0;
}
