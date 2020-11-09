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