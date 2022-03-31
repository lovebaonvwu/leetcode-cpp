class Solution {
  vector<vector<int>> memo;
  vector<int> sums;

 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();
    memo = vector<vector<int>>(n, vector<int>(m + 1, INT_MAX));
    sums = vector<int>(n);
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + nums[i];
    }

    return dfs(nums, n - 1, m);
  }

  int dfs(const vector<int>& nums, int k, int m) {
    if (m == 1) {
      return sums[k];
    }

    if (m > k + 1) {
      return INT_MAX;
    }

    if (memo[k][m] != INT_MAX) {
      return memo[k][m];
    }

    int ans = INT_MAX;

    for (int i = 0; i < k; ++i) {
      ans = min(ans, max(dfs(nums, i, m - 1), sums[k] - sums[i]));
    }

    return memo[k][m] = ans;
  }
};
// Runtime: 901 ms, faster than 10.62%
// Memory Usage: 8.2 MB, less than 11.32%
// 2022.3.31 at 茗筑美嘉