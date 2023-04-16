class Solution {
  long long dp[1001][1001];
  int cnt[1001][26];

 public:
  int numWays(vector<string>& words, string target) {
    int m = target.size();
    int n = words[0].size();
    int mod = 1e9 + 7;

    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < words.size(); ++i) {
        ++cnt[j][words[i][j] - 'a'];
      }
    }

    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i][j - 1];
        if (cnt[j - 1][target[i - 1] - 'a'] > 0) {
          dp[i][j] +=
              (dp[i - 1][j - 1] * cnt[j - 1][target[i - 1] - 'a']) % mod;
        }

        dp[i][j] %= mod;
      }
    }

    return dp[m][n];
  }
};
// Runtime 259 ms
// Memory 34.9 MB