#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long a, b;
  cin >> a >> b;

  cout << ((a * 12) + b);

  return 0;
}
