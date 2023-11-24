class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    function<int(int, int)> dfs = [&](int i, int remain) -> int {
      if (remain <= 0) {
        return 0;
      }

      if (i == n) {
        return 1e9;
      }

      if (dp[i][remain] != -1) {
        return dp[i][remain];
      }

      int paint = cost[i] + dfs(i + 1, remain - 1 - time[i]);
      int dontPaint = dfs(i + 1, remain);

      return dp[i][remain] = min(paint, dontPaint);
    };

    return dfs(0, n);
  }
};
// 247ms
// 116.18MB