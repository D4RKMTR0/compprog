#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string enemyPos;
    string pos;
    int pawnsReached = 0;

    cin >> enemyPos;
    cin >> pos;

    for (size_t i = 0; i < n; i++) {
      if (pos[i] == '0') {
        continue;
      }

      if (i - 1 >= 0 && enemyPos[i - 1] == '1') {
        enemyPos[i - 1] = '0';
        pawnsReached++;
        continue;
      }

      if (enemyPos[i] == '0') {
        pawnsReached++;
        continue;
      }

      if (i + 1 < n && enemyPos[i + 1] == '1') {
        enemyPos[i + 1] = '0';
        pawnsReached++;
      }
    }

    cout << pawnsReached << '\n';
  }

  return 0;
}
