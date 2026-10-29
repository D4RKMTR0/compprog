#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  cin >> n;

  cout << n << ' ';

  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = (n * 3) + 1;
    }

    cout << n << ' ';
  }

  return 0;
}
