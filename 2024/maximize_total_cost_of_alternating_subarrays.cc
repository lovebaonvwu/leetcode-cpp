class Solution {
 public:
  long long maximumTotalCost(vector<int>& nums) {
    int n = nums.size();

    vector<long long> cached(n, -1);

    function<long long(int)> dfs = [&](int k) -> long long {
      if (k == n)
        return 0;

      if (cached[k] != -1)
        return cached[k];

      long long ret = INT_MIN;
      long long sum = 0;
      int sign = 1;
      for (int i = k; i < n; ++i) {
        sum += sign * nums[i];
        sign *= -1;
        ret = max(ret, sum + dfs(i + 1));
      }

      return cached[k] = ret;
    };

    return dfs(0);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long maximumTotalCost(vector<int>& nums) {
    int n = nums.size();

    vector<vector<long long>> dp(n, vector<long long>(2, INT_MIN));
    dp[0][0] = nums[0];
    dp[0][1] = nums[0];

    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + nums[i];
      dp[i][1] = dp[i - 1][0] - nums[i];
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
// 170 ms
// 112.30 MB