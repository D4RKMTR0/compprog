#include <vector>
#include <string>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
      std::string encodedString = "";
      
      for (std::string str : strs) {
        encodedString += (std::to_string(str.length()) + "#" + str);
      } 

      return encodedString;
    }

    std::vector<std::string> decode(std::string s) {
      std::vector<std::string> strs;
      int i = 0;

      while (i < s.length()) {
        size_t hash_pos = s.find('#', i);
        int length = std::stoi(s.substr(i, hash_pos - i));
        i = hash_pos + 1;
        strs.push_back(s.substr(i, length));
        i += length;
      }

      return strs;
    }
};
