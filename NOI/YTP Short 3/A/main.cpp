#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n, x, y;
  cin >> n >> x >> y;

  vector<double> nbk(n);
  vector<long long> cts(5, 0);

  for (int i = 0; i < n; i++) {
    cin >> nbk[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        array<double, 3> arr = {nbk[i], nbk[j], nbk[k]};
        sort(arr.begin(), arr.end());

        double mn = arr[0];
        double md = arr[1];
        double mx = arr[2];

        bool fe = true;

        if (mx <= x) {cts[0]++; fe = false;}
        if (x <= mn && mx <= y) {cts[1]++; fe = false;}
        if (y <= mn) {cts[2]++; fe = false;}
        if (mn <= x && x <= md && md <= y && y <= mx) {cts[3]++; fe = false;}

        if (fe == true) cts[4]++;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    cout << cts[i] << " ";
  }

  return 0;
}
