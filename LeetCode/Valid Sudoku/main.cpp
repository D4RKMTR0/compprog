#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> seen;

    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[r].size(); c++) {
        char num = board[r][c];
        if (num == '.') continue;
        
        std::string rowTag = {std::to_string(num) + " row: " + std::to_string(r)};
        std::string colTag = {std::to_string(num) + " col: " + std::to_string(c)};
        std::string boxTag = {std::to_string(num) + " box: " + std::to_string((r / 3) * 3 + (c / 3))};

        if (seen.count(rowTag) || seen.count(colTag) || seen.count(boxTag)) {
          return false;
        }

        seen.insert(rowTag);
        seen.insert(colTag);
        seen.insert(boxTag);
      }
    }

    return true;
  }
};