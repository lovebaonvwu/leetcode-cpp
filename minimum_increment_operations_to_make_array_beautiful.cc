class Solution {
 public:
  long long minIncrementOperations(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> dp(n, -1);

    function<long long(int)> dfs = [&](int i) -> long long {
      if (i > n - 3) {
        return 0;
      }

      if (dp[i] != -1) {
        return dp[i];
      }

      long long a = max(0, k - nums[i]) + dfs(i + 1);
      long long b = max(0, k - nums[i + 1]) + dfs(i + 2);
      long long c = max(0, k - nums[i + 2]) + dfs(i + 3);

      return dp[i] = min({a, b, c});
    };

    return dfs(0);
  }
};
// 155ms
// 146.21MB