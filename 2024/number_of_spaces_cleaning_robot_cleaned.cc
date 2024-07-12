class Solution {
 public:
  int numberOfCleanRooms(vector<vector<int>>& room) {
    int m = room.size();
    int n = room[0].size();
    vector<vector<vector<bool>>> visited(
        m, vector<vector<bool>>(n, vector<bool>(4)));
    vector<int> dirs = {0, 1, 0, -1, 0};

    function<void(int, int, int)> dfs = [&](int y, int x, int d) -> void {
      if (visited[y][x][d])
        return;

      visited[y][x][d] = true;

      int dy = y + dirs[d];
      int dx = x + dirs[d + 1];

      if (dy < 0 || dy == m || dx < 0 || dx == n || room[dy][dx] == 1)
        return dfs(y, x, (d + 1) % 4);
      return dfs(dy, dx, d);
    };

    dfs(0, 0, 0);

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (room[i][j] == 0 && (visited[i][j][0] || visited[i][j][1] ||
                                visited[i][j][2] || visited[i][j][3])) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 117 ms
// 59.97 MB
