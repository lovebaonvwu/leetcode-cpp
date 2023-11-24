class Solution {
 public:
  int waysToReachTarget(int target, vector<vector<int>>& types) {
    int n = types.size();
    vector<vector<int>> dp(target + 1, vector<int>(n, -1));
    int mod = 1e9 + 7;
    function<int(int, int)> dfs = [&](int target, int i) -> int {
      if (target == 0) {
        return 1;
      }

      if (i == n || target < 0) {
        return 0;
      }

      if (dp[target][i] != -1) {
        return dp[target][i];
      }

      dp[target][i] = 0;

      for (int k = 0; k <= types[i][0]; ++k) {
        dp[target][i] =
            (dp[target][i] + dfs(target - (k * types[i][1]), i + 1)) % mod;
      }

      return dp[target][i];
    };

    return dfs(target, 0);
  }
};
// 1018ms
// 16.74MB