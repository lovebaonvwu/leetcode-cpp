class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (dp[i][j]) {
        return dp[i][j];
      }

      if (i == j) {
        return nums[i];
      }

      return dp[i][j] = max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1));
    };

    return dfs(0, n - 1) >= 0;
  }
};
// 4ms
// 7.82mb