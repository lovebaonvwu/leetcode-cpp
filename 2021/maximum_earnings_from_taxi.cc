class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<long long> dp(n + 1);

    sort(rides.begin(), rides.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    for (int i = 1, j = 0; i <= n; ++i) {
      dp[i] = dp[i - 1];

      while (j < rides.size() && rides[j][1] == i) {
        dp[i] = max(dp[i],
                    dp[rides[j][0]] + rides[j][1] - rides[j][0] + rides[j][2]);
        ++j;
      }
    }

    return dp[n];
  }
};
// Runtime: 508 ms, faster than 80.34%
// Memory Usage: 106.8 MB, less than 60.67%
// 2021.9.22 at 奥盛大厦