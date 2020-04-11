class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(),
         [](auto& a, auto& b) { return a[1] - a[0] > b[1] - b[0]; });

    int ans = 0;

    size_t n = costs.size();

    for (int i = 0; i < n / 2; ++i) {
      ans += costs[i][0] + costs[i + n / 2][1];
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 34.68%
// Memory Usage: 7 MB, less than 100.00%

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    size_t n = costs.size();
    vector<vector<int>> mem(n / 2 + 1, vector<int>(n / 2 + 1));

    return dfs(costs, mem, 0, n / 2, n / 2);
  }

  int dfs(vector<vector<int>>& costs,
          vector<vector<int>>& mem,
          int i,
          int a,
          int b) {
    if (i >= costs.size()) {
      return 0;
    }

    if (a > 0 && b > 0 && mem[a][b] > 0) {
      return mem[a][b];
    }

    int ca = INT_MAX, cb = INT_MAX;

    if (a > 0) {
      ca = costs[i][0] + dfs(costs, mem, i + 1, a - 1, b);
    }

    if (b > 0) {
      cb = costs[i][1] + dfs(costs, mem, i + 1, a, b - 1);
    }

    mem[a][b] = min(ca, cb);

    return mem[a][b];
  }
};
// Runtime: 8 ms, faster than 34.68%
// Memory Usage: 7.2 MB, less than 100.00%

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    size_t n = costs.size() / 2;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
    }

    for (int i = 1; i <= n; ++i) {
      dp[0][i] = dp[0][i - 1] + costs[i - 1][1];
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = min(dp[i - 1][j] + costs[i + j - 1][0],
                       dp[i][j - 1] + costs[i + j - 1][1]);
      }
    }

    return dp[n][n];
  }
};
// Runtime: 8 ms, faster than 34.68%
// Memory Usage: 7.4 MB, less than 100.00%