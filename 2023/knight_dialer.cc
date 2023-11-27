class Solution {
 public:
  int knightDialer(int n) {
    vector<vector<int>> dp(10, vector<int>(n + 1, -1));
    int mod = 1e9 + 7;
    vector<vector<int>> moves{
        {4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
        {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4},
    };

    function<int(int, int)> dfs = [&](int cur, int n) -> int {
      if (n == 0)
        return 1;
      if (dp[cur][n] != -1)
        return dp[cur][n];
      int cnt = 0;
      for (auto& move : moves[cur]) {
        cnt = (cnt + dfs(move, n - 1)) % mod;
      }

      return dp[cur][n] = cnt;
    };

    int ans = 0;
    for (int i = 0; i < 10; ++i) {
      ans = (ans + dfs(i, n - 1)) % mod;
    }

    return ans % mod;
  }
};
// 178ms
// 25.05MB