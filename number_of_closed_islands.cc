class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;

    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (grid[i][j] == 0) {
          bfs(grid, i, j, ans);
        }
      }
    }

    return ans;
  }

 private:
  void bfs(vector<vector<int>>& g, int i, int j, int& ans) {
    int m = g.size();
    int n = g[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});

    bool valid = true;
    int dir[] = {1, 0, -1, 0, 1};
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      g[y][x] = max(2, ans + 2);

      for (int k = 0; k < 4; ++k) {
        int dy = y + dir[k];
        int dx = x + dir[k + 1];

        if (dy < 0 || dy == m || dx < 0 || dx == n) {
          continue;
        }

        if (g[dy][dx] != 0) {
          continue;
        }

        if (dy == 0 || dy == m - 1 || dx == 0 || dx == n - 1) {
          valid = false;
        }

        q.push({dy, dx});
      }
    }

    ans += valid;
  }
};
// Runtime 15 ms
// Memory 14.3 MB