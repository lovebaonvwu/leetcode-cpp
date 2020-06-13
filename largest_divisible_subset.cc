class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    size_t n = nums.size();

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int mx = 0;
    int mx_idx = -1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }

      if (dp[i] > mx) {
        mx = dp[i];
        mx_idx = i;
      }
    }

    vector<int> ans;
    while (mx_idx > -1) {
      ans.push_back(nums[mx_idx]);
      mx_idx = prev[mx_idx];
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 76.59%
// Memory Usage: 8.7 MB, less than 45.40%