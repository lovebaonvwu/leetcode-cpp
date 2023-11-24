class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        pq;
    pq.push({0, 0, 0});

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!pq.empty()) {
      auto [d, i, j] = pq.top();
      pq.pop();

      if (i == m - 1 && j == n - 1) {
        return d;
      }

      for (auto& [dx, dy] : dirs) {
        int x = i + dx;
        int y = j + dy;

        if (x < 0 || y < 0 || x == m || y == n) {
          continue;
        }

        if (d + grid[x][y] < dist[x][y]) {
          dist[x][y] = d + grid[x][y];
          pq.push({dist[x][y], x, y});
        }
      }
    }

    return dist[m - 1][n - 1];
  }
};
// Runtime: 938 ms, faster than 63.95%
// Memory Usage: 104.1 MB, less than 72.96%
// 2022.8.3 at 奥盛大厦