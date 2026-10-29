#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    string word;
    cin >> n >> word;

    int count = 0;

    for (int i = 0; i < n; i++) {
      char currentChar = word[i];
      if (currentChar != word[n-1]) {
        count++;
      }
    }

    cout << count << '\n';
  }

  return 0;
}
