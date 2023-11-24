class Solution {
 public:
  double soupServings(int n) {
    n = (n + 25 - 1) / 25;
    if (n > 500) {
      return 1;
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));

    function<double(int, int)> dfs = [&](int a, int b) -> double {
      if (a <= 0 && b > 0) {
        return 1.0;
      }
      if (a <= 0 && b <= 0) {
        return 0.5;
      }
      if (a > 0 && b <= 0) {
        return 0;
      }

      if (dp[a][b] != -1) {
        return dp[a][b];
      }

      return dp[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
                                dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
    };

    return dfs(n, n);
  }
};
// -ms
// 6.99mb