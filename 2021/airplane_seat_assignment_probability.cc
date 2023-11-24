class Solution {
 public:
  double nthPersonGetsNthSeat(int n) { return n == 1 ? 1.0 : 0.5; }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%

class Solution {
 public:
  double nthPersonGetsNthSeat(int n) {
    if (n == 1) {
      return 1.0;
    }

    return 1.0 / n + (n - 2.0) / n * nthPersonGetsNthSeat(n - 1);
  }
};
// Runtime: 20 ms, faster than 15.00%
// Memory Usage: 11.6 MB, less than 100.00%

class Solution {
 public:
  double nthPersonGetsNthSeat(int n) {
    vector<double> dp(n);

    dp[0] = 1.0;

    for (int i = 1; i < n; ++i) {
      dp[i] = 1.0 / (i + 1) + (i + 1 - 2.0) / (i + 1) * dp[i - 1];
    }

    return dp.back();
  }
};
// Runtime: 24 ms, faster than 8.72%
// Memory Usage: 40.7 MB, less than 100.00%