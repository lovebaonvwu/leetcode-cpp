class Solution {
 public:
  int minCost(vector<int>& houses,
              vector<vector<int>>& cost,
              int m,
              int n,
              int target) {
    constexpr int kInf = 1e9 + 7, s = 1;
    vector<vector<vector<int>>> dp(
        target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, kInf)));

    fill(begin(dp[0][0]), end(dp[0][0]), 0);

    for (int k = 1; k <= target; ++k) {
      for (int i = k; i <= m; ++i) {
        const int hi = houses[i - 1];
        const int hj = i >= 2 ? houses[i - 2] : 0;

        const auto& [si, ei] = hi ? tie(hi, hi) : tie(s, n);
        const auto& [sj, ej] = hj ? tie(hj, hj) : tie(s, n);

        for (int ci = si; ci <= ei; ++ci) {
          const int v = ci == hi ? 0 : cost[i - 1][ci - 1];
          for (int cj = sj; cj <= ej; ++cj) {
            dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v);
          }
        }
      }
    }

    int ans = *min_element(begin(dp[target][m]), end(dp[target][m]));

    return ans == kInf ? -1 : ans;
  }
};
// Runtime: 153 ms, faster than 43.08%
// Memory Usage: 19.7 MB, less than 6.38%
// 2022.7.8 at 奥盛大厦