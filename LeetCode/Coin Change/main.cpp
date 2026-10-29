#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  long long solve(vector<int>& coins, long long total, long long target, vector<long long>& memo) {
    if (total == target) return 0;
    if (total > target) return LLONG_MAX;

    if (memo[total] != -1) return memo[total];

    long long minCoins = LLONG_MAX;

    for (int i = 0; i < coins.size(); i++) {
      long long sub = solve(coins, total + coins[i], target, memo);
      if (sub != LLONG_MAX) {
        minCoins = min(minCoins, sub + 1);
      }
    }

    return memo[total] = minCoins;
  }

  int coinChange(vector<int>& coins, int amount) {
    vector<long long> memo(amount + 1);

    fill(memo.begin(), memo.end(), -1);

    return solve(coins, 0, amount, memo);
  }
};
