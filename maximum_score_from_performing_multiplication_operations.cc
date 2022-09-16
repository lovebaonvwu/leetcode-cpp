class Solution {
  vector<vector<int>> memo;
  int m;
  int n;

 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    m = multipliers.size();
    n = nums.size();
    memo.resize(m + 1, vector<int>(m + 1, INT_MIN));
    return dfs(nums, multipliers, 0, 0, n - 1);
  }

  int dfs(vector<int>& nums, vector<int>& multipliers, int k, int l, int r) {
    if (k == m) {
      return 0;
    }

    if (memo[l][k] != INT_MIN) {
      return memo[l][k];
    }

    int val1 = nums[l] * multipliers[k];
    int val2 = nums[r] * multipliers[k];
    return memo[l][k] = max(val1 + dfs(nums, multipliers, k + 1, l + 1, r),
                            val2 + dfs(nums, multipliers, k + 1, l, r - 1));
  }
};
// Runtime: 540 ms, faster than 74.90%
// Memory Usage: 120.1 MB, less than 66.36%
// 2022.9.16 at 新泰市协庄煤矿医院