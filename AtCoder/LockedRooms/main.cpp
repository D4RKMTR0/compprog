#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> l(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }

  vector<bool> reachable(n + 1, false);

  reachable[0] = true;
  for (int i = 1; i <= n; i++) {
    if (l[i] == 0) {
      reachable[i] = true;
    } else {
      break;
    }
  }

  reachable[n] = true;
  for (int i = n; i >= 1; i--) {
    if (l[i] == 0) {
      reachable[i - 1] = true;
    } else {
      break;
    }
  }

  int unreachable_count = 0;
  for (int i = 0; i <= n; i++) {
    if (!reachable[i]) {
      unreachable_count++;
    }
  }

  cout << unreachable_count << '\n';
  return 0;
}
