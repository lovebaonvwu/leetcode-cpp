class Solution {
 public:
  bool canSplitArray(vector<int>& nums, int m) {
    int n = nums.size();
    if (n == 2) {
      return true;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    function<int(int, int)> dfs = [&](int l, int r) -> int {
      if (l == r) {
        return 1;
      }

      if (dp[l][r] != -1) {
        return dp[l][r];
      }

      if (presum[r + 1] - presum[l] < m) {
        return dp[l][r] = 0;
      }

      bool res = false;
      for (int i = l; i < r; ++i) {
        if (dfs(l, i) && dfs(i + 1, r)) {
          return dp[l][r] = 1;
        }
      }

      return dp[l][r] = 0;
    };

    return dfs(0, n - 1) == 1;
  }
};
// Runtime 218 ms
// Memory 26.5 MB