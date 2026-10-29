  #include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;

    if (k < n - 1) {
      cout << n << "\n";
    } else {
      cout << 1 << "\n";
    }
  }

  return 0;
}
