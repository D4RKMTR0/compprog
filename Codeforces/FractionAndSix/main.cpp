#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    string p, q;
    cin >> p >> q;

    vector<int> cntp(26, 0);
    vector<int> cntq(26, 0);

    for (char c : p) {
        cntp[c - 'a']++;
    }

    for (char c : q) {
        cntq[c - 'a']++;
    }

    vector<int> tgt(26, 0);
    tgt['s' - 'a']++;
    tgt['i' - 'a']++;
    tgt['x' - 'a']++;

    bool possible = true;
    for (int i = 0; i < 26; i++) {
        if (cntp[i] != cntq[i] + tgt[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
