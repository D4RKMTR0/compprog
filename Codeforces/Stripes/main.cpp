#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    array<string, 8> grid;
    char complete = 'n';

    for (size_t i = 0; i < 8; i++) {
      string row;
      cin >> row;

      grid[i] = row;
    }

    for (size_t i = 0; i < 8; i++) {
      bool valid = true;
      char last = 'n';

      for (size_t j = 0; j < 8; j++) {
        char current = grid[i][j];

        if (current == 'R' || current == 'B') {
          if (last == 'n') {
            last = current;
            continue;
          }

          if (last == current) {
            valid = false;
            break;

          }
        } else {
          valid = false;
          break;
        }
      }

      if (valid) {
        complete = last;
        break;
      }
    }

    cout << complete << '\n';
  }

  return 0;
}
