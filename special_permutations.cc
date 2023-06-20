class Solution {
  vector<vector<int>> dp;
  int mod;
  int n;

 public:
  int specialPerm(vector<int>& nums) {
    n = nums.size();
    dp.resize(n, vector<int>((1 << n) - 1, -1));
    mod = 1e9 + 7;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + dfs(nums, i, 0 | (1 << i))) % mod;
    }
    return ans;
  }

  int dfs(const vector<int>& nums, int i, int mask) {
    if (mask == (1 << n) - 1) {
      return 1;
    }

    if (dp[i][mask] >= 0) {
      return dp[i][mask];
    }

    int cnt = 0;
    for (int k = 0; k < n; ++k) {
      if (mask & (1 << k)) {
        continue;
      }

      if (nums[k] % nums[i] == 0 || nums[i] % nums[k] == 0) {
        cnt = (cnt + dfs(nums, k, mask | (1 << k))) % mod;
      }
    }

    return dp[i][mask] = cnt;
  }
};
// Runtime 416 ms
// Memory 75 MB