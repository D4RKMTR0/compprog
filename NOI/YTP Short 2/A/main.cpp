#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Camp {
  long long l;
  long long r;
  vector<long long> subj;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  deque<Camp> joined;
  vector<long long> sums;

  sums.resize(k, 0);

  while (n--) {
    Camp camp;
    cin >> camp.l >> camp.r;

    for (size_t i = 0; i < k; i++) {
      long long num;
      cin >> num;

      camp.subj.push_back(num);
    }

    if (joined.empty()) {
      joined.push_back(camp);
      continue;
    }

    auto top = joined.back();

    if (top.r < camp.l) {
      joined.push_back(camp);
    } else {
      int aMore = 0;
      int bMore = 0;

      for (int i = 0; i < k; i++) {
        if (top.subj[i] > camp.subj[i]) {
          aMore++;
        } else if (camp.subj[i] > top.subj[i]) {
          bMore++;
        }
      }

      if (bMore > aMore) {
        joined.pop_back();
        joined.push_back(camp);
      }
    }
  }

  for (const auto& camp : joined) {
    for (size_t i = 0; i < k; i++) {
      sums[i] += camp.subj[i];
    }
  }

  long long mini = *min_element(sums.begin(), sums.end());
  cout << mini << '\n';

  return 0;
}
