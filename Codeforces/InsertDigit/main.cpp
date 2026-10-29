#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    char d;
    string num;
    cin >> n >> d >> num;

    string result = num;
    bool inserted = false;

    for (int i = 0; i < n; i++) {
      if (num[i] < d) {
        result.insert(i, 1, d);
        inserted = true;
        break;
      }
    }

    if (!inserted) {
      result += d;
    }

    cout << result << '\n';
  }

  return 0;
}
