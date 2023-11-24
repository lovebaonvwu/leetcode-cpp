class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();

    int dirs[] = {0, -1, 0, 1, 0};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }

        int sur = grid[i][j] * 4;  // side surface

        for (int k = 0; k < 4; ++k) {
          int dx = i + dirs[k];
          int dy = j + dirs[k + 1];

          if (dx < 0 || dy < 0 || dx == m || dy == n) {
            continue;
          }

          sur -= min(grid[i][j], grid[dx][dy]);
        }

        ans += 2;  // top and bottom
        ans += sur;
      }
    }

    return ans;
  }
};
// Runtime: 9 ms, faster than 84.47%
// Memory Usage: 9.3 MB, less than 88.20%
// 2022.6.21 at 奥盛大厦