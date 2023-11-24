class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (auto& c : coins) {
      for (int i = c; i <= amount; ++i) {
        dp[i] = min(dp[i], 1 + dp[i - c]);
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};
// Runtime: 36 ms, faster than 88.92%
// Memory Usage: 12.5 MB, less than 90.20%

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      for (auto& c : coins) {
        if (i >= c) {
          dp[i] = min(dp[i], 1 + dp[i - c]);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};
// Runtime: 40 ms, faster than 82.54%
// Memory Usage: 12.6 MB, less than 86.27%

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      int res = -1;

      for (auto& c : coins) {
        if (i >= c && dp[i - c] >= 0) {
          int cnt = 1 + dp[i - c];
          res = res < 0 ? cnt : min(res, cnt);
        }
      }

      dp[i] = res;
    }

    return dp[amount];
  }
};
// Runtime: 48 ms, faster than 67.87%
// Memory Usage: 12.6 MB, less than 84.31%

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);

    return coin(coins, dp, amount);
  }

  int coin(vector<int>& coins, vector<int>& dp, int amount) {
    if (amount < 0) {
      return -1;
    }

    if (amount == 0) {
      return 0;
    }

    if (dp[amount] > 0 || dp[amount] < 0) {
      return dp[amount];
    }

    int ans = -1;

    for (auto& c : coins) {
      int res = coin(coins, dp, amount - c);

      if (res >= 0) {
        ans = ans < 0 ? 1 + res : min(ans, 1 + res);
      }
    }

    dp[amount] = ans;

    return ans;
  }
};
// Runtime: 100 ms, faster than 12.11%
// Memory Usage: 14.4 MB, less than 27.45%

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> dp;

    return coin(coins, dp, amount);
  }

  int coin(vector<int>& coins, unordered_map<int, int>& dp, int amount) {
    if (amount < 0) {
      return -1;
    }

    if (amount == 0) {
      return 0;
    }

    if (dp[amount] > 0 || dp[amount] < 0) {
      return dp[amount];
    }

    int ans = -1;

    for (auto& c : coins) {
      int res = coin(coins, dp, amount - c);

      if (res >= 0) {
        ans = ans < 0 ? 1 + res : min(ans, 1 + res);
      }
    }

    dp[amount] = ans;

    return ans;
  }
};
// Runtime: 508 ms, faster than 5.48%
// Memory Usage: 60.9 MB, less than 11.76%