#include <iostream>
#include <set>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  cin >> q;

  multiset<int> bag;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;

      bag.insert(x);
      continue;
    }

    cout << *bag.begin() << '\n';
    bag.erase(bag.begin());
  }

  return 0;
}
