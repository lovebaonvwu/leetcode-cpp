class Solution {
  vector<vector<int>> dp;

 public:
  int change(int amount, vector<int>& coins) {
    dp.resize(coins.size() + 1, vector<int>(amount + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= coins.size(); ++i) {
      dp[i][0] = 1;

      for (int j = 1; j <= amount; ++j) {
        dp[i][j] =
            dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
      }
    }

    return dp[coins.size()][amount];
  }
};
// Runtime: 36 ms, faster than 34.76%
// Memory Usage: 18.6 MB, less than 18.75%

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= coins.size(); ++i) {
      dp[i][0] = 1;

      for (int j = 1; j <= amount; ++j) {
        dp[i][j] =
            dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
      }
    }

    return dp[coins.size()][amount];
  }
};
// Runtime: 32 ms, faster than 37.72%
// Memory Usage: 18.4 MB, less than 25.42%

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);

    dp[0] = 1;

    for (auto c : coins) {
      for (int i = c; i <= amount; ++i) {
        dp[i] += dp[i - c];
      }
    }

    return dp[amount];
  }
};
// Runtime: 4 ms, faster than 99.30%
// Memory Usage: 7.2 MB, less than 70.12%