#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

std::vector<std::string> notInOrphans(const std::vector<std::string>& tiles) {
  std::set<std::string> orphans = {"1m", "9m", "1p", "9p", "1s", "9s", "E", "S", "W", "N", "Wh", "G", "R"};
  std::unordered_map<std::string, int> counts;
  std::vector<std::string> unneededTiles;

  bool pairAssigned = false;

  for (const auto& tile : tiles) {
    if (orphans.count(tile)) {
      counts[tile]++;

      if (counts[tile] == 1) {
        continue;
      } else if (counts[tile] == 2 && !pairAssigned) {
        pairAssigned = true;
      } else {
        unneededTiles.push_back(tile);
      }
    } else {
      unneededTiles.push_back(tile);
    }
  }

  return unneededTiles;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<string> tiles;

  for (int i = 0; i < 13; i++) {
    string tile;
    cin >> tile;

    tiles.push_back(tile);
  }

  while (true) {
    string cmd;
    string tile;
    cin >> cmd >> tile;

    tiles.push_back(tile);

    auto unneededItems = notInOrphans(tiles);
    if (unneededItems.size() > 0) {
      auto item = std::find(tiles.begin(), tiles.end(), unneededItems[0]);
      tiles.erase(item);

      cout << "DROP " << unneededItems[0] << '\n' << std::flush;
      continue;
    }

    if (tiles.size() == 14) {
      cout << "CALL\n" << std::flush;
      break;
    }
  }

  return 0;
}
