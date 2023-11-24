class Solution {
 public:
  int countVowelStrings(int n) {
    int cnt[5] = {1, 1, 1, 1, 1};

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 5; ++j) {
        int c = 0;
        for (int k = j; k < 5; ++k) {
          c += cnt[k];
        }
        cnt[j] = c;
      }
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
      ans += cnt[i];
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 36.56%

class Solution {
 public:
  int countVowelStrings(int n) {
    int dp[6] = {0, 1, 1, 1, 1, 1};

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 5; ++j) {
        dp[j] += dp[j - 1];
      }
    }

    return dp[5];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 36.56%

class Solution {
 public:
  int countVowelStrings(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6));

    for (int j = 1; j < 6; ++j) {
      dp[1][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < 6; ++j) {
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[n][5];
  }
};
// Runtime: 2 ms, faster than 49.32%
// Memory Usage: 6.3 MB, less than 22.78%
// 2022.5.11 at 奥盛大厦