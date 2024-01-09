class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    vector<int> dp(100011, -1);

    function<int(int)> dfs = [&](int x) -> int {
      if (x == y)
        return 0;
      if (x < y)
        return y - x;

      if (dp[x] != -1)
        return dp[x];

      int res = INT_MAX;
      res = min(res, 1 + dfs(x - 1));
      res = min(res, 1 + (11 - x % 11) + dfs(x / 11 + 1));
      res = min(res, 1 + x % 11 + dfs(x / 11));
      res = min(res, 1 + (5 - x % 5) + dfs(x / 5 + 1));
      res = min(res, 1 + x % 5 + dfs(x / 5));

      return dp[x] = res;
    };

    return dfs(x);
  }
};
// 68ms
// 308.68MB