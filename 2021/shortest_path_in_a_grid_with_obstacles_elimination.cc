class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});

    vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
    visited[0][0] = 0;

    vector<int> dirs = {0, 1, 0, -1, 0};

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        int x, y, e;

        tie(x, y, e) = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1) {
          return ans;
        }

        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];

          if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
            continue;
          }

          int de = e + grid[dx][dy];

          if (de >= visited[dx][dy] || de > k) {
            continue;
          }

          visited[dx][dy] = de;

          q.push({dx, dy, de});
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime: 16 ms, faster than 88.10%
// Memory Usage: 9.8 MB, less than 84.32%
// 2021.9.25 at 茗筑美嘉