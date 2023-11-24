class Solution {
 public:
  int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();

    vector<int> dp = {1, 0, 1};

    for (auto n : obstacles) {
      if (n > 0) {
        dp[n - 1] = 1e6;
      }

      for (int i = 0; i < 3; ++i) {
        if (i == n - 1) {
          continue;
        }

        dp[i] = min(dp[i], min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + 1);
      }
    }

    return min({dp[0], dp[1], dp[2]});
  }
};
// Runtime: 260 ms, faster than 75.04%
// Memory Usage: 188.1 MB, less than 60.86%