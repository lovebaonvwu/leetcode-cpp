class Solution {
 public:
  int profitableSchemes(int n,
                        int minProfit,
                        vector<int>& group,
                        vector<int>& profit) {
    vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
    dp[0][0] = 1;

    int mod = 1e9 + 7;
    for (int k = 0; k < group.size(); ++k) {
      int p = profit[k], g = group[k];
      for (int i = minProfit; i >= 0; --i) {
        for (int j = n - g; j >= 0; --j) {
          dp[min(minProfit, i + p)][j + g] =
              (dp[min(minProfit, i + p)][j + g] + dp[i][j]) % mod;
        }
      }
    }

    int ans = 0;
    for (auto cnt : dp[minProfit]) {
      ans = (ans + cnt) % mod;
    }

    return ans;
  }
};
// Runtime 131 ms
// Memory 9.2 MB