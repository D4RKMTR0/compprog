#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long t;
  cin >> t;

  while (t--) {
    long long ro, x, d, n;
    string rounds;
    long long roundsParticipated = 0;
    cin >> ro >> x >> d >> n >> rounds;

    for (int i = 0; i < n; i++) {
      if (rounds[i] == '1' || ro < x) {
        ro = max(0LL, ro - d);
        roundsParticipated++;
        continue;
      }
    }

    cout << roundsParticipated << '\n';
  }

  return 0;
}
