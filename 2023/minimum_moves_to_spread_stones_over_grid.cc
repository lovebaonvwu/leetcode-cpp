class Solution {
 public:
  int minimumMoves(vector<vector<int>>& grid) { return dfs(grid); }

  int dfs(vector<vector<int>>& grid) {
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cnt += grid[i][j] == 1;
      }
    }

    if (cnt == 9) {
      return 0;
    }

    int ans = INT_MAX / 2;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int y = 0; y < 3; ++y) {
          for (int x = 0; x < 3; ++x) {
            if (grid[i][j] == 0 && grid[y][x] > 1) {
              int d = abs(i - y) + abs(j - x);
              grid[i][j] += 1;
              grid[y][x] -= 1;
              ans = min(ans, d + dfs(grid));
              grid[i][j] -= 1;
              grid[y][x] += 1;
            }
          }
        }
      }
    }

    return ans;
  }
};
// 2326ms
// 18.76MB