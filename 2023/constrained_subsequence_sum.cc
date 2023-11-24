class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1);

    int ans = INT_MIN;
    for (int j = 1; j <= n; ++j) {
      dp[j] = nums[j - 1];
      for (int i = max(0, j - k); i < j; ++i) {
        dp[j] = max(dp[j], nums[j - 1] + dp[i]);
      }

      ans = max(ans, dp[j]);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    int n = nums.size();
    pq.push({nums[0], 0});
    int ans = nums[0];

    for (int i = 1; i < n; ++i) {
      while (i - pq.top().second > k) {
        pq.pop();
      }

      int cur = max(0, pq.top().first) + nums[i];
      ans = max(ans, cur);
      pq.push({cur, i});
    }

    return ans;
  }
};
// 282 ms
// 139.5 MB