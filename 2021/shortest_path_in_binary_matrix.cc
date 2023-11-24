class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    queue<vector<int>> q;

    if (grid[0][0]) {
      return -1;
    }

    q.push({0, 0});
    grid[0][0] = 1;

    int ans = 1;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto p = q.front();
        q.pop();

        int x = p[0];
        int y = p[1];

        if (x == grid.size() - 1 && y == grid.size() - 1) {
          return ans;
        }

        for (int i = -1; i <= 1; ++i) {
          for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
              continue;
            }

            int dx = x + i;
            int dy = y + j;

            if (dx < 0 || dy < 0 || dx == grid.size() || dy == grid.size() ||
                grid[dx][dy]) {
              continue;
            }

            q.push({dx, dy});
            grid[dx][dy] = 1;
          }
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime: 124 ms, faster than 49.67%
// Memory Usage: 36.8 MB, less than 24.24%