class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        if (!dp[i - j * j]) {
          dp[i] = true;
        }
      }
    }

    return dp[n];
  }
};
// Runtime: 784 ms, faster than 10.23%
// Memory Usage: 6.8 MB, less than 5.18%

class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
// Runtime: 196 ms, faster than 42.70%
// Memory Usage: 6.8 MB, less than 5.18%

class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<int> mem(n + 1, -1);

    return dfs(n, mem);
  }

  int dfs(int n, vector<int>& mem) {
    if (n == 0) {
      return 0;
    }

    if (mem[n] > -1) {
      return mem[n];
    }

    int win = false;

    for (int i = 1; i * i <= n; ++i) {
      if (!winnerSquareGame(n - i * i)) {
        win = true;
        break;
      }
    }

    return mem[n] = win;
  }
};
// Time Limit Exceeded