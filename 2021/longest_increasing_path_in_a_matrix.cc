class Solution {
  int m;
  int n;
  vector<int> dirs{0, 1, 0, -1, 0};

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();

    vector<vector<int>> memo(m, vector<int>(n));

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dfs(matrix, memo, i, j, -1));
      }
    }

    return ans;
  }

  int dfs(vector<vector<int>>& mat,
          vector<vector<int>>& memo,
          int x,
          int y,
          int val) {
    if (x < 0 || y < 0 || x == m || y == n) {
      return 0;
    }

    if (mat[x][y] <= val) {
      return 0;
    }

    if (memo[x][y] > 0) {
      return memo[x][y];
    }

    for (int i = 0; i < 4; ++i) {
      int dx = x + dirs[i];
      int dy = y + dirs[i + 1];

      memo[x][y] = max(memo[x][y], dfs(mat, memo, dx, dy, mat[x][y]) + 1);
    }

    return memo[x][y];
  }
};
// Runtime: 48 ms, faster than 47.19%
// Memory Usage: 16 MB, less than 76.26%