class Solution {
 public:
  int getFood(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m && q.empty(); ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '*') {
          q.push({i, j});
          break;
        }
      }
    }

    int ans = 0;
    int dirs[] = {1, 0, -1, 0, 1};
    while (!q.empty()) {
      int cnt = q.size();
      while (cnt-- > 0) {
        auto [y, x] = q.front();
        q.pop();

        if (grid[y][x] == '#') {
          return ans;
        }

        for (int k = 0; k < 4; ++k) {
          int dy = y + dirs[k];
          int dx = x + dirs[k + 1];

          if (dy < 0 || dy == m || dx < 0 || dx == n) {
            continue;
          }

          if (grid[dy][dx] == 'X' || grid[dy][dx] == '*') {
            continue;
          }

          grid[dy][dx] = grid[dy][dx] == 'O' ? 'X' : grid[dy][dx];
          q.push({dy, dx});
        }
      }
      ++ans;
    }

    return -1;
  }
};
// 53 ms
// 21.36 MB