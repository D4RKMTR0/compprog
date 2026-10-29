#include <iostream>
#include <stack>  
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long q;
  cin >> q;

  stack<long long> cards;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      long long card;
      cin >> card;

      cards.push(card);
    }

    if (type == 2) {
      if (cards.empty()) {
        cout << 0 << '\n';
        continue;
      }
      cout << cards.top() << '\n';
      cards.pop();
    }
  }

  return 0;
}
