#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  bool same = false;
  string lastTimeStamp;
  vector<string> chronostasisTimes;

  while (n--) {
    string currentTimeStamp;
    cin >> currentTimeStamp;

    if (lastTimeStamp.empty()) {
      lastTimeStamp = currentTimeStamp;
      continue;
    }

    if (currentTimeStamp == lastTimeStamp) {
      if (!same) {
        chronostasisTimes.push_back(currentTimeStamp);
        same = true;
      }
    } else {
      same = false;
    }

    lastTimeStamp = currentTimeStamp;
  }

  cout << chronostasisTimes.size() << '\n';
  for (auto timestamp : chronostasisTimes) {
    cout << timestamp << '\n';
  }

  return 0;
}
