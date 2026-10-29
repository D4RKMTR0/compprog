#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  cin >> n;

  long long totalSum = (n * (n + 1)) / 2;
  long long sum = 0;

  for (int i = 0; i < n-1; i++) {
    long long num;
    cin >> num;

    sum += num;
  }

  cout << (totalSum - sum) << '\n';

  return 0;
}
