#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, c, k;
    cin >> n >> c >> k;

    vector<long long> enemies;

    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;

      enemies.push_back(a);
    }

    sort(enemies.begin(), enemies.end());

    for (int i = 0; i < n; i++) {
      long long currentEnemy = enemies[i];

      if (currentEnemy < c && k > 0) {
        long long add = min(c - currentEnemy, k);
        k -= add;
        currentEnemy += add;
      }

      if (currentEnemy <= c) {
        c += currentEnemy;
      }
    }

    cout << c << '\n';
  }

  return 0;
}
