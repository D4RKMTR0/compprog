#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> keymap;
    std::vector<std::vector<std::string>> anagrams;

    for (std::string string : strs) {
      std::string sortedString = string;
      std::sort(sortedString.begin(), sortedString.end());
      keymap[sortedString].push_back(string);
    }

    for (const auto& entry : keymap) {
      anagrams.push_back(entry.second);
    }

    return anagrams;
  }
};