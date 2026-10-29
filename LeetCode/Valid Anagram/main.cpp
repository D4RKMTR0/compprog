#include <iostream>
#include <string>
#include <unordered_map>

auto speedup = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, int> counts;

    for (char c : s) {
      counts[c]++;
    } 

    for (char c : t) {
      counts[c]--;

      if (counts[c] < 0) {
        return false;
      }
    }

    return true;
  }
};