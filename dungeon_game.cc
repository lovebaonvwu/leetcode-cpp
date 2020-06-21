class Solution {
  int ans = INT_MIN;

 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    dfs(dungeon, 0, 0, 0, 0);

    ans = 0 - ans + 1;

    return ans > 0 ? ans : 0;
  }

  void dfs(vector<vector<int>>& dungeon, int minhp, int curhp, int i, int j) {
    if (i > dungeon.size() - 1 || j > dungeon[0].size() - 1) {
      return;
    }

    curhp = curhp + dungeon[i][j];
    minhp = min(minhp, curhp);

    if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
      ans = max(ans, minhp);
      return;
    }

    dfs(dungeon, minhp, curhp, i, j + 1);
    dfs(dungeon, minhp, curhp, i + 1, j);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = need <= 0 ? 1 : need;
      }
    }

    return dp[0][0];
  }
};
// Runtime: 16 ms, faster than 34.25%
// Memory Usage: 9.2 MB, less than 9.75%