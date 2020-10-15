class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    queue<vector<int>> q;

    vector<vector<int>> ans;
    vector<vector<int>> visited(R, vector<int>(C));

    q.push({r0, c0});

    visited[r0][c0] = 1;

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      ans.push_back(p);

      if (p[0] + 1 < R && !visited[p[0] + 1][p[1]]) {
        q.push({p[0] + 1, p[1]});
        visited[p[0] + 1][p[1]] = 1;
      }

      if (p[1] + 1 < C && !visited[p[0]][p[1] + 1]) {
        q.push({p[0], p[1] + 1});
        visited[p[0]][p[1] + 1] = 1;
      }

      if (p[0] - 1 >= 0 && !visited[p[0] - 1][p[1]]) {
        q.push({p[0] - 1, p[1]});
        visited[p[0] - 1][p[1]] = 1;
      }

      if (p[1] - 1 >= 0 && !visited[p[0]][p[1] - 1]) {
        q.push({p[0], p[1] - 1});
        visited[p[0]][p[1] - 1] = 1;
      }
    }

    return ans;
  }
};
// Runtime: 88 ms, faster than 63.08%
// Memory Usage: 25 MB, less than 7.17%

class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;

    vector<vector<vector<int>>> dis(R * C);

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int distance = abs(i - r0) + abs(j - c0);

        dis[distance].push_back({i, j});
      }
    }

    for (auto& d : dis) {
      for (auto& a : d) {
        ans.push_back(a);
      }
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 76.79%
// Memory Usage: 27 MB, less than 7.17%

class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;

    map<int, vector<vector<int>>> dis;

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int distance = abs(i - r0) + abs(j - c0);

        dis[distance].push_back({i, j});
      }
    }

    for (auto& d : dis) {
      for (auto& a : d.second) {
        ans.push_back(a);
      }
    }

    return ans;
  }
};
// Runtime: 76 ms, faster than 82.28%
// Memory Usage: 25.3 MB, less than 7.17%