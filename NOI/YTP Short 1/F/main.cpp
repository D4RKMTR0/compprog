#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

struct Compare {
  bool operator()(const std::pair<std::string, long long>& a, const std::pair<std::string, long long>& b) const {
    return a.second < b.second;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n, k;
  cin >> n >> k;

  bool possible = true;
  long long count = 0;
  long long sum = 0;
  priority_queue<pair<string, long long>, vector<pair<string, long long>>, Compare> songs;
  queue<pair<pair<string, long long>, long long>> cooldowns;
  vector<string> output;

  for (int i = 0; i < n; i++) {
    long long c;
    string song;
    cin >> c >> song;

    sum += c;
    songs.push({song, c});
  }

  while (count < sum) {
    while (!cooldowns.empty() && cooldowns.front().second <= count) {
      songs.push(cooldowns.front().first);
      cooldowns.pop();
    }

    if (songs.empty()) {
      possible = false;
      break;
    }

    auto currentSong = songs.top();
    songs.pop();

    output.push_back(currentSong.first);
    currentSong.second--;

    if (currentSong.second > 0) {
      cooldowns.push({{currentSong.first, currentSong.second}, count + k});
    }

    count++;
  }

  if (!possible) {
    cout << "Crisis!" << '\n';
  }

  if (possible) {
    cout << sum << '\n';
    for (size_t i = 0; i < output.size(); i++) {
      cout << output[i] << '\n';
    }
  }

  return 0;
}
