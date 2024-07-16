class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();

    vector<int> dirs = {1, 0, -1, 0, 1};

    function<void(int, int)> bfs = [&](int i, int j) -> void {
      queue<array<int, 3>> q;
      q.push({i, j, 0});

      while (!q.empty()) {
        auto [y, x, d] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
          int dy = y + dirs[k];
          int dx = x + dirs[k + 1];

          if (dy == m || dy < 0 || dx == n || dx < 0) {
            continue;
          }

          if (rooms[dy][dx] == -1) {
            continue;
          }

          if (d + 1 > rooms[dy][dx]) {
            continue;
          }

          rooms[dy][dx] = d + 1;
          q.push({dy, dx, d + 1});
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          bfs(i, j);
        }
      }
    }
  }
};
// Time Limit Exceeded

class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();

    vector<int> dirs = {1, 0, -1, 0, 1};
    queue<array<int, 3>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          q.push({i, j, 0});
        }
      }
    }

    while (!q.empty()) {
      auto [y, x, d] = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        int dy = y + dirs[k];
        int dx = x + dirs[k + 1];

        if (dy == m || dy < 0 || dx == n || dx < 0) {
          continue;
        }

        if (rooms[dy][dx] != INT_MAX) {
          continue;
        }

        rooms[dy][dx] = d + 1;
        q.push({dy, dx, d + 1});
      }
    }
  }
};
// 20 ms
// 17.54 MB
