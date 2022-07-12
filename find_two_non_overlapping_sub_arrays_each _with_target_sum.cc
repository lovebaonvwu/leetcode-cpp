class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();

    vector<int> dp(n, INT_MAX);

    int ans = INT_MAX;
    for (int l = 0, r = 0, sum = 0; r < n; ++r) {
      sum += arr[r];

      while (sum > target) {
        sum -= arr[l++];
      }

      if (sum == target) {
        dp[r] = r - l + 1;

        if (l > 0 && dp[l - 1] < INT_MAX) {
          ans = min(ans, dp[r] + dp[l - 1]);
        }
      }

      if (r > 0) {
        dp[r] = min(dp[r - 1], dp[r]);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// Runtime: 168 ms, faster than 76.64%
// Memory Usage: 74.2 MB, less than 84.61%
// 2022.7.12 at 奥盛大厦