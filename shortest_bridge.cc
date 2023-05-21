class Solution {
  queue<pair<int, int>> q;
  int m;
  int n;

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; ++i) {
      int stopScan = false;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j);
          stopScan = true;
          break;
        }
      }

      if (stopScan) {
        break;
      }
    }

    int ans = 0;
    int dirs[] = {0, 1, 0, -1, 0};

    while (!q.empty()) {
      int cnt = q.size();

      int connected = false;

      while (cnt-- > 0) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
          int di = i + dirs[k];
          int dj = j + dirs[k + 1];

          if (di < 0 || di == m || dj < 0 || dj == n) {
            continue;
          }

          if (grid[di][dj] > 1) {
            continue;
          }

          if (grid[di][dj] == 1) {
            connected = true;
            break;
          }

          grid[di][dj] = ans + 3;
          q.push({di, dj});
        }

        if (connected) {
          break;
        }
      }

      if (connected) {
        break;
      }

      ++ans;
    }

    return ans;
  }

  void dfs(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n) {
      return;
    }

    if (g[i][j] != 1) {
      return;
    }

    g[i][j] = 2;
    q.push({i, j});

    dfs(g, i, j + 1);
    dfs(g, i, j - 1);
    dfs(g, i + 1, j);
    dfs(g, i - 1, j);
  }
};
// Runtime 44 ms
// Memory 20 MB