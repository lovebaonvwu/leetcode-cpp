class Solution {
 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    vector<vector<int>>& g = grid;
    queue<array<int, 2>> q;
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == 1) {
          q.push({i, j});
        }
      }
    }

    int dirs[] = {1, 0, -1, 0, 1};
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        int y = i + dirs[k];
        int x = j + dirs[k + 1];

        if (y < 0 || y == n || x < 0 || x == n) {
          continue;
        }

        if (g[y][x] == 0 || g[y][x] > g[i][j] + 1) {
          g[y][x] = g[i][j] + 1;
          q.push({y, x});
        }
      }
    }

    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});

    while (!pq.empty()) {
      auto [d, i, j] = pq.top();
      pq.pop();

      if (i == n - 1 && j == n - 1) {
        return d - 1;
      }

      for (int k = 0; k < 4; ++k) {
        int y = i + dirs[k];
        int x = j + dirs[k + 1];

        if (y < 0 || y == n || x < 0 || x == n || g[y][x] == -1) {
          continue;
        }

        pq.push({min(g[y][x], d), y, x});
        g[y][x] = -1;
      }
    }

    return 0;
  }
};
// 479ms
// 110.08mb