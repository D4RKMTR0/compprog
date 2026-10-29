#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string>& lnd, vector<bool>& tkn, size_t idx, int& cnt) {
  if (idx == lnd.size()) {
    cnt++;
    return;
  }

  bool skp = false;

  for (size_t i = 0; i < lnd.size(); i++) {
    if (lnd[idx][i] == 'C') {
      skp = true;
      solve(lnd, tkn, idx+1, cnt);
    }
  }

  if (skp) {
    return;
  }

  for (size_t i = 0; i < tkn.size(); i++) {
    if (tkn[i] == false) {
      if (lnd[idx][i] == 'X') continue; 

      tkn[i] = true;
      solve(lnd, tkn, idx+1, cnt);
      tkn[i] = false;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  cin >> n;

  vector<bool> tkn(n, false);
  vector<string> lnd(n);

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    cin >> lnd[i];
  }

  for (int i = 0; i < n; i++) {
    bool tken = false;
    int c = 0;

    for (int j = 0; j < n; j++) {
      if (lnd[i][j] == 'C') {
        tken = true;
        c = j;
        break;
      }
    }

    if (tken == true) {
      tkn[c] = true;
    }
  }

  solve(lnd, tkn, 0, cnt);

  cout << cnt << '\n';

  return 0;
}
