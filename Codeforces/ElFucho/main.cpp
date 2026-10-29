#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    long long matchesPlayed = 0;
    long long winners = n;
    long long losers = 0;

    while (winners > 1 || losers > 1) {
      if (winners > 1) {
        winners--;
        losers++;
        matchesPlayed++;
      }

      if (losers > 1) {
        losers--;
        matchesPlayed++;
      }
    }

    cout << (matchesPlayed += 1LL) << '\n';
  }

  return 0;
}
