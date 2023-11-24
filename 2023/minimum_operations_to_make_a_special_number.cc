class Solution {
 public:
  int minimumOperations(string num) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(25, -1));

    function<int(int, int, const string&)> dfs = [&](int i, int cur,
                                                     const string& s) -> int {
      if (i == n) {
        if (cur % 25 == 0) {
          return 0;
        } else {
          return n;
        }
      }

      if (dp[i][cur] != -1) {
        return dp[i][cur];
      }

      return dp[i][cur] = min(1 + dfs(i + 1, cur, s),
                              dfs(i + 1, (cur * 10 + (s[i] - '0')) % 25, s));
    };

    return dfs(0, 0, num);
  }
};
// 20ms
// 10.91MB