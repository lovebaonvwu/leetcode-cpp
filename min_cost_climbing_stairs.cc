class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size(), -1);

    return ccs(cost, 0, dp);
  }

  int ccs(vector<int>& cost, int i, vector<int>& dp) {
    if (i >= cost.size() - 1) {
      return 0;
    }

    if (dp[i] > -1) {
      return dp[i];
    }

    dp[i] =
        min(cost[i] + ccs(cost, i + 1, dp), cost[i + 1] + ccs(cost, i + 2, dp));

    return dp[i];
  }
};
// Runtime: 8 ms, faster than 60.23%
// Memory Usage: 9.1 MB, less than 11.63%

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) { return ccs(cost, 0); }

  int ccs(vector<int>& cost, int i) {
    if (i >= cost.size() - 1) {
      return 0;
    }

    return min(cost[i] + ccs(cost, i + 1), cost[i + 1] + ccs(cost, i + 2));
  }
};
// Time Limit Exceeded