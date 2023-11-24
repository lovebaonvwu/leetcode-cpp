class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});

    int dirs[] = {0, -1, 0, 1, 0};

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto [x, y] = q.front();
        q.pop();

        visited[x][y] = true;

        if ((x == 0 || y == 0 || x == m - 1 || y == n - 1) &&
            !(x == entrance[0] && y == entrance[1])) {
          return ans;
        }

        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];

          if (dx < 0 || dy < 0 || dx == m || dy == n) {
            continue;
          }

          if (maze[dx][dy] == '+') {
            continue;
          }

          if (visited[dx][dy]) {
            continue;
          }

          q.push({dx, dy});
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Time Limit Exceeded
// 2021.7.15 at 奥盛大厦

class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();

    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});

    int dirs[] = {0, -1, 0, 1, 0};

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto [x, y] = q.front();
        q.pop();

        maze[x][y] = '+';

        if ((x == 0 || y == 0 || x == m - 1 || y == n - 1) &&
            !(x == entrance[0] && y == entrance[1])) {
          return ans;
        }

        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];

          if (dx < 0 || dy < 0 || dx == m || dy == n) {
            continue;
          }

          if (maze[dx][dy] == '+') {
            continue;
          }

          q.push({dx, dy});
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime: 116 ms, faster than 86.80%
// Memory Usage: 29.9 MB, less than 82.76%
// 2021.7.15 at 奥盛大厦