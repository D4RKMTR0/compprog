#include <iostream>
#include <stack>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    string log;
    cin >> n >> log;

    stack<char> questions;

    for (int i = 0; i < n; i++) {
      char currentChar = log[i];
      if (currentChar == 'Q') {
        questions.push(currentChar);
      } else {
        if (!questions.empty()) {
          questions.pop();
        }
      }
    }

    cout << (questions.empty() ? "Yes" : "No") << '\n';
  }

  return 0;
}
