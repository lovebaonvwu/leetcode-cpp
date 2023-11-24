class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<bool>>> visited(
        m, vector<vector<bool>>(n, vector<bool>(64, 0)));
    queue<array<int, 3>> q;
    int target = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '@') {
          q.push({i, j, 0});
          visited[i][j][0] = true;
        } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
          target |= (1 << (grid[i][j] - 'a'));
        }
      }
    }

    int ans = 0;
    int dirs[] = {1, 0, -1, 0, 1};
    while (!q.empty()) {
      int size = q.size();
      while (size-- > 0) {
        auto [y, x, keys] = q.front();
        q.pop();

        if (keys == target) {
          return ans;
        }

        for (int k = 0; k < 4; ++k) {
          int dy = y + dirs[k];
          int dx = x + dirs[k + 1];
          int tmp = keys;

          if (dy < 0 || dy == m || dx < 0 || dx == n) {
            continue;
          }

          const char c = grid[dy][dx];
          if (c == '#') {
            continue;
          }

          if (c >= 'A' && c <= 'F' && !(tmp & (1 << (c - 'A')))) {
            continue;
          }

          if (c >= 'a' && c <= 'f') {
            tmp |= (1 << (c - 'a'));
          }

          if (visited[dy][dx][tmp]) {
            continue;
          }

          q.push({dy, dx, tmp});
          visited[dy][dx][tmp] = true;
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime 33 ms
// Memory 10.8 MB