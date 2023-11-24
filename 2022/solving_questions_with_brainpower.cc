class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();

    vector<long long> dp(n);
    dp[n - 1] = questions[n - 1][0];

    for (int i = n - 2; i >= 0; --i) {
      int& points = questions[i][0];
      int& bp = questions[i][1];

      if (i + bp >= n - 1) {
        dp[i] = max(static_cast<long long>(points), dp[i + 1]);
      } else {
        dp[i] = max(dp[i + 1], dp[i + bp + 1] + points);
      }
    }

    return dp[0];
  }
};
// Runtime: 386 ms, faster than 79.25%
// Memory Usage: 115.2 MB, less than 84.25%
// 2022.1.19 at 奥盛大厦