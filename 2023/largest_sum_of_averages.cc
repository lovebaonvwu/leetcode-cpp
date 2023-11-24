class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<double>> dp(n, vector<double>(k + 1, -1));

    function<double(int, int)> dfs = [&](int i, int k) -> double {
      if (k == 1 && i < n) {
        return accumulate(begin(nums) + i, end(nums), 0.0) / (n - i);
      }

      if (i >= n) {
        return 0;
      }

      if (dp[i][k] != -1) {
        return dp[i][k];
      }

      double sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        dp[i][k] = max(sum / (j - i + 1) + dfs(j + 1, k - 1), dp[i][k]);
      }
      return dp[i][k];
    };

    return dfs(0, k);
  }
};
// 29ms
// 8.25MB