class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);

    dp[n - 1] = 0;
    dp[n - 2] = min(cost[n - 2], cost[n - 1]);

    for (int i = n - 3; i >= 0; --i) {
      dp[i] = min(cost[i] + dp[i + 1], cost[i + 1] + dp[i + 2]);
    }

    return dp[0];
  }
};
// Runtime: 4 ms, faster than 98.18%
// Memory Usage: 8.6 MB, less than 97.67%

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
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());

    for (int i = cost.size() - 1; i >= 0; --i) {
      if (i >= cost.size() - 1) {
        dp[i] = 0;
      } else {
        if (i + 2 > dp.size() - 1) {
          dp[i] = min(cost[i] + dp[i + 1], cost[i + 1]);
        } else {
          dp[i] = min(cost[i] + dp[i + 1], cost[i + 1] + dp[i + 2]);
        }
      }
    }

    return dp[0];
  }
};
// Runtime: 12 ms, faster than 10.11%
// Memory Usage: 8.6 MB, less than 97.67%

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