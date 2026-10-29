#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long p;
    cin >> p;

    vector<long long> parties;

    for (int i = 0; i < p; i++) {
      long long num;
      cin >> num;

      parties.push_back(num);
    }

    
  }

  return 0;
}
