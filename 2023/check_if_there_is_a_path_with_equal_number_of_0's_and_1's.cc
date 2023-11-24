class Solution {
  int m;
  int n;

 public:
  bool isThereAPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    if ((m + n) % 2 == 0) {
      return false;
    }

    return dfs(grid, 0, 0, grid[0][0] == 1);
  }

  bool dfs(vector<vector<int>>& g, int i, int j, int ones) {
    if (i >= m || j >= n) {
      return false;
    }

    if (i == m - 1 && j == n - 1) {
      return ones == m + n - 1 - ones;
    }

    return dfs(g, i + 1, j, ones + g[i][j]) || dfs(g, i, j + 1, ones + g[i][j]);
  }
};
// Time Limit Exceeded

class Solution {
  int m;
  int n;
  int memo[101][101][201];

 public:
  bool isThereAPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    memset(memo, 0, sizeof(memo));

    if ((m + n) % 2 == 0) {
      return false;
    }

    return dfs(grid, 0, 0, grid[0][0] == 1);
  }

  bool dfs(vector<vector<int>>& g, int i, int j, int ones) {
    if (i >= m || j >= n) {
      return false;
    }

    if (ones > (m + n - 1) / 2) {
      return false;
    }

    if (memo[i][j][ones]) {
      return false;
    }

    memo[i][j][ones] = true;

    if (i == m - 1 && j == n - 1) {
      return ones == m + n - 1 - ones;
    }

    return dfs(g, i + 1, j, ones + g[i][j]) || dfs(g, i, j + 1, ones + g[i][j]);
  }
};
// Runtime 38 ms
// Memory 18.1 MB
// 2023.1.11 at 奥盛大厦