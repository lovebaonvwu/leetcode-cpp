class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i == n1) {
        int res = 0;
        while (j < n2) {
          res += s2[j++];
        }
        return res;
      }

      if (j == n2) {
        int res = 0;
        while (i < n1) {
          res += s1[i++];
        }
        return res;
      }

      if (dp[i][j] != -1) {
        return dp[i][j];
      }

      if (s1[i] == s2[j]) {
        dp[i][j] = dfs(i + 1, j + 1);
      } else {
        dp[i][j] = min(s1[i] + dfs(i + 1, j), s2[j] + dfs(i, j + 1));
      }

      return dp[i][j];
    };

    return dfs(0, 0);
  }
};
// 91ms
// 15.29mb