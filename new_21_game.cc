class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    vector<double> dp(k + maxPts);
    for (int i = k; i < min(n + 1, k + maxPts); ++i) {
      dp[i] = 1.0;
    }

    double cnt = min(n - k + 1, maxPts) * 1.0;
    for (int i = k - 1; i >= 0; --i) {
      dp[i] = cnt / maxPts;
      cnt += dp[i] - dp[i + maxPts];
    }

    return dp[0];
  }
};
// Runtime 6 ms
// Memory 10.7 MB