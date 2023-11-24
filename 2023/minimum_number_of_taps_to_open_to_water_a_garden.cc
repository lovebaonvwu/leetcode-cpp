class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    const int INF = 1e9 + 7;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i <= n; ++i) {
      int left = max(0, i - ranges[i]);
      int right = min(n, i + ranges[i]);

      for (int j = left; j <= right; ++j) {
        dp[right] = min(dp[right], dp[j] + 1);
      }
    }

    return dp[n] == INF ? -1 : dp[n];
  }
};
// 23ms
// 14.63MB