class Solution {
  int dp[51][51][51][4] = {};
  int dfs(int x, int y, int z, int last) {
    if (dp[x][y][z][last] > 0) {
      return dp[x][y][z][last];
    }

    int cnt = 0;
    if (x > 0 && last != 1) {
      cnt = max(cnt, 2 + dfs(x - 1, y, z, 1));
    }
    if (y > 0 && last <= 1) {
      cnt = max(cnt, 2 + dfs(x, y - 1, z, 2));
    }
    if (z > 0 && last != 1) {
      cnt = max(cnt, 2 + dfs(x, y, z - 1, 3));
    }

    return dp[x][y][z][last] = cnt;
  }

 public:
  int longestString(int x, int y, int z) { return dfs(x, y, z, 0); }
};
// Runtime 242 ms
// Memory 8.3 MB