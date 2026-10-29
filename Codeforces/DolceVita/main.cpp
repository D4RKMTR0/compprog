#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long t;
  cin >> t;

  while (t--) {
    long long n, x;
    cin >> n >> x;

    vector<long long> prices;
    long long add = 0;
    long long packsBought = 0;

    for (size_t i = 0; i < n; i++) {
      int price;
      cin >> price;

      prices.push_back(price);
    }

    sort(prices.begin(), prices.end());

    while (prices[0] + add <= x) {
      long long budget = x;

      for (long long price : prices) {
        long long dayPrice = price + add;

        if (budget >= dayPrice) {
          budget -= dayPrice;
          packsBought++;
          continue;
        } else {
          break;
        }
      }

      add++;
    }

    cout << packsBought << '\n';
  }

  return 0;
}
