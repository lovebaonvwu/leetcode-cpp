class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();
    int n = isWater[0].size();

    vector<vector<int>> ans(m, vector<int>(n, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j]) {
          ans[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    vector<int> dirs = {0, 1, 0, -1, 0};
    while (!q.empty()) {
      for (int cnt = q.size(); cnt > 0; --cnt) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];

          if (dx < 0 || dy < 0 || dx == m || dy == n) {
            continue;
          }

          if (ans[dx][dy] > -1) {
            continue;
          }

          ans[dx][dy] = ans[x][y] + 1;

          q.push({dx, dy});
        }
      }
    }

    return ans;
  }
};
// Runtime: 300 ms, faster than 81.82%
// Memory Usage: 108.1 MB, less than 9.09%