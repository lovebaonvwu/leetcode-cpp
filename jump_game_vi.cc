class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> dp(n, INT_MIN / 2);

    dp[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= max(0, i - k); --j) {
        dp[i] = max(dp[i], dp[j] + nums[i]);
      }
    }

    return dp[n - 1];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();

    deque<pair<int, int>> dq;

    dq.push_back({nums[0], 0});

    int cur = 0;

    for (int i = 1; i < n; ++i) {
      if (i - dq.front().second > k) {
        dq.pop_front();
      }

      cur = nums[i] + dq.front().first;

      while (!dq.empty() && cur >= dq.back().first) {
        dq.pop_back();
      }

      dq.push_back({cur, i});
    }

    return dq.back().first;
  }
};
// Runtime: 172 ms, faster than 53.04%
// Memory Usage: 77.8 MB, less than 81.94%