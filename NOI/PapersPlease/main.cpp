#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAXLEN = 250005;

struct State {
    int len, link;
    int next[26];
};

State st[MAXLEN * 2];
int sz, last;

void init() {
  for (int i = 0; i < sz; i++) {
    st[i].len = 0;
    st[i].link = 0;
    memset(st[i].next, -1, sizeof(st[i].next));
  }

  st[0].len = 0;
  st[0].link = -1;
  memset(st[0].next, -1, sizeof(st[0].next));
  sz = 1;
  last = 0;
}

void extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  memset(st[cur].next, -1, sizeof(st[cur].next));

  int p = last;
  while (p != -1 && st[p].next[c - 'A'] == -1) {
    st[p].next[c - 'A'] = cur;
    p = st[p].link;
  }

  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c - 'A'];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c - 'A'] == q) {
        st[p].next[c - 'A'] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }

  last = cur;
}

vector<vector<int>> buildTable(const string &s) {
  int n = s.length();
  vector<vector<int>> nxt(n + 1, vector<int>(26, -1));

  int idx = -1;
  for (int c = 0; c < 26; c++) {
    idx = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] - 'A' == c) idx = i;
      nxt[i][c] = idx;
    }
  }

  return nxt;
}

bool isSubstring(const string &n) {
  int curr = 0;

  for (char ch : n) {
    int c = ch - 'A';

    if (st[curr].next[c] == -1) {
      return false;
    }

    curr = st[curr].next[c];
  }

  return true;
}

bool isSubsequence(const string &name, const vector<vector<int>> &nxt, int n) {
  int curr = 0;

  for (char ch : name) {
    int c = ch - 'A';
    if (curr >= n || nxt[curr][c] == -1) {
      return false;
    }

    curr = nxt[curr][c] + 1;
  }

  return true;
}

void solve() {
  long long n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  init();

  for (const char c : s) {
    extend(c);
  }

  vector<vector<int>> nxt = buildTable(s);

  for (int i = 0; i < q; i++) {
    long long l;
    string p;
    cin >> l >> p;

    if (isSubstring(p)) {
      cout << "DETAINED" << '\n';
    } else if (isSubsequence(p, nxt, n)) {
      cout << "DENIED" << '\n';
    } else {
      cout << "APPROVED" << '\n';
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
