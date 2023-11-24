class Solution {
 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n));

    visited[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      if (grid[i][j] == 1) {
        if (j + 1 < n && !visited[i][j + 1] &&
            (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
             grid[i][j + 1] == 5)) {
          q.push({i, j + 1});
          visited[i][j + 1] = 1;
        }

        if (j - 1 >= 0 && !visited[i][j - 1] &&
            (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
             grid[i][j - 1] == 6)) {
          q.push({i, j - 1});
          visited[i][j - 1] = 1;
        }
      } else if (grid[i][j] == 2) {
        if (i + 1 < m && !visited[i + 1][j] &&
            (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
             grid[i + 1][j] == 6)) {
          q.push({i + 1, j});
          visited[i + 1][j] = 1;
        }

        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
             grid[i - 1][j] == 4)) {
          q.push({i - 1, j});
          visited[i - 1][j] == 1;
        }
      } else if (grid[i][j] == 3) {
        if (j - 1 >= 0 && !visited[i][j - 1] &&
            (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
             grid[i][j - 1] == 6)) {
          q.push({i, j - 1});
          visited[i][j - 1] = 1;
        }

        if (i + 1 < m && !visited[i + 1][j] &&
            (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
             grid[i + 1][j] == 6)) {
          q.push({i + 1, j});
          visited[i + 1][j] = 1;
        }
      } else if (grid[i][j] == 4) {
        if (j + 1 < n && !visited[i][j + 1] &&
            (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
             grid[i][j + 1] == 5)) {
          q.push({i, j + 1});
          visited[i][j + 1] = 1;
        }

        if (i + 1 < m && !visited[i + 1][j] &&
            (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 ||
             grid[i + 1][j] == 6)) {
          q.push({i + 1, j});
          visited[i + 1][j] = 1;
        }
      } else if (grid[i][j] == 5) {
        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
             grid[i - 1][j] == 4)) {
          q.push({i - 1, j});
          visited[i - 1][j] == 1;
        }

        if (j - 1 >= 0 && !visited[i][j - 1] &&
            (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 ||
             grid[i][j - 1] == 6)) {
          q.push({i, j - 1});
          visited[i][j - 1] = 1;
        }
      } else {
        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 ||
             grid[i - 1][j] == 4)) {
          q.push({i - 1, j});
          visited[i - 1][j] == 1;
        }

        if (j + 1 < n && !visited[i][j + 1] &&
            (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 ||
             grid[i][j + 1] == 5)) {
          q.push({i, j + 1});
          visited[i][j + 1] = 1;
        }
      }
    }

    return visited[m - 1][n - 1];
  }
};
// Runtime: 956 ms, faster than 9.47%
// Memory Usage: 114 MB, less than 100.00%

class Solution {
  vector<vector<pair<int, int>>> moves = {
      {{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}},  {{0, -1}, {1, 0}},
      {{0, 1}, {1, 0}},  {{0, -1}, {-1, 0}}, {{0, 1}, {-1, 0}}};

 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n));

    visited[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (auto [ii, jj] : moves[grid[i][j] - 1]) {
        int x = i + ii;
        int y = j + jj;

        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
          continue;
        }

        for (auto [ii, jj] : moves[grid[x][y] - 1]) {
          if (x + ii == i && y + jj == j) {
            q.push({x, y});
            visited[x][y] = 1;
          }
        }
      }
    }

    return visited[m - 1][n - 1];
  }
};
// Runtime: 220 ms, faster than 56.29%
// Memory Usage: 31.3 MB, less than 100.00%

class Solution {
  vector<vector<pair<int, int>>> moves = {
      {{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}},  {{0, -1}, {1, 0}},
      {{0, 1}, {1, 0}},  {{0, -1}, {-1, 0}}, {{0, 1}, {-1, 0}}};

  vector<vector<int>> visited;

 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    visited = vector(m, vector<int>(n));

    visited[0][0] = 1;

    dfs(grid, 0, 0);

    return visited[m - 1][n - 1];
  }

  void dfs(vector<vector<int>>& grid, int i, int j) {
    for (auto [ii, jj] : moves[grid[i][j] - 1]) {
      int x = i + ii;
      int y = j + jj;

      if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
          visited[x][y]) {
        continue;
      }

      for (auto [ii, jj] : moves[grid[x][y] - 1]) {
        if (x + ii == i && y + jj == j) {
          visited[x][y] = 1;
          dfs(grid, x, y);
        }
      }
    }
  }
};
// Runtime: 196 ms, faster than 65.26%
// Memory Usage: 74.9 MB, less than 100.00%