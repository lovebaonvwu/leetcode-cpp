class Solution {
  int ans = 0;
  int m;
  int n;

 public:
  int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0) {
          bfs(grid, i, j);
        }
      }
    }

    return ans;
  }

  void bfs(vector<vector<int>>& g, int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    int dirs[] = {0, 1, 0, -1, 0};

    int cnt = 0;
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      cnt += g[y][x];

      g[y][x] = 0;

      for (int k = 0; k < 4; ++k) {
        int dy = y + dirs[k];
        int dx = x + dirs[k + 1];

        if (dy == m || dy < 0 || dx == n || dx < 0 || g[dy][dx] == 0) {
          continue;
        }

        q.push({dy, dx});
      }
    }

    ans = max(ans, cnt);
  }
};
// Runtime 134 ms
// Memory 108.5 MB

class Solution {
  int m;
  int n;

 public:
  int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dfs(grid, i, j));
      }
    }

    return ans;
  }

  int dfs(vector<vector<int>>& g, int y, int x) {
    if (y == m || y < 0 || x == n || x < 0 || g[y][x] == 0) {
      return 0;
    }

    int cnt = g[y][x];
    g[y][x] = 0;

    return cnt + dfs(g, y + 1, x) + dfs(g, y - 1, x) + dfs(g, y, x + 1) +
           dfs(g, y, x - 1);
  }
};
// Runtime 76 ms
// Memory 88.5 MB