class Solution {
 public:
  int findCheapestPrice(int n,
                        vector<vector<int>>& flights,
                        int src,
                        int dst,
                        int K) {
    vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));

    for (int i = 0; i < K + 2; ++i) {
      dp[i][src] = 0;
    }

    for (int i = 1; i < K + 2; ++i) {
      for (auto& f : flights) {
        if (dp[i - 1][f[0]] != INT_MAX) {
          dp[i][f[1]] = min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]);
        }
      }
    }

    return dp[K + 1][dst] == INT_MAX ? -1 : dp[K + 1][dst];
  }
};
// Runtime: 44 ms, faster than 60.54%
// Memory Usage: 11 MB, less than 68.63%