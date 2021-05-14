class Solution {
 public:
  int maxSumMinProduct(vector<int>& nums) {
    int mod = 1e9 + 7, n = nums.size();

    vector<long long> presum(n + 1);

    for (int i = 1; i < presum.size(); ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = nums[i];

      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
      }
    }

    long long ans = 0LL;

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        ans = max<long long>(ans, dp[i][j] * (presum[j + 1] - presum[i]));
      }
    }

    return ans % mod;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxSumMinProduct(vector<int>& nums) {
    int mod = 1e9 + 7, n = nums.size();

    vector<long long> presum(n + 1);

    for (int i = 1; i < presum.size(); ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    vector<int> next(n), prev(n);

    stack<int> stk;

    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i] <= nums[stk.top()]) {
        stk.pop();
      }

      next[i] = stk.empty() ? n : stk.top();

      stk.push(i);
    }

    while (!stk.empty()) {
      stk.pop();
    }

    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[i] <= nums[stk.top()]) {
        stk.pop();
      }

      prev[i] = stk.empty() ? -1 : stk.top();

      stk.push(i);
    }

    long long ans = 0LL;

    for (int i = 0; i < n; ++i) {
      int p = prev[i] + 1;
      int q = next[i] - 1;

      ans = max(ans, nums[i] * (presum[q + 1] - presum[p]));
    }

    return ans % mod;
  }
};
// Runtime: 244 ms, faster than 58.67%
// Memory Usage: 90.2 MB, less than 61.87%