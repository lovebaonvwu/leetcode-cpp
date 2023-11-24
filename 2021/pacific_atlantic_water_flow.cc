class Solution {
  int m;
  int n;

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> ans;

    m = matrix.size();
    if (!m) {
      return ans;
    }

    n = matrix[0].size();
    if (!n) {
      return ans;
    }

    vector<vector<int>> pacific(m, vector<int>(n));
    vector<vector<int>> altantic(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      dfs(matrix, pacific, i, 0);
      dfs(matrix, altantic, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
      dfs(matrix, pacific, 0, j);
      dfs(matrix, altantic, m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && altantic[i][j]) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

  void dfs(const vector<vector<int>>& mat,
           vector<vector<int>>& visited,
           int x,
           int y) {
    vector<int> dirs = {0, 1, 0, -1, 0};

    visited[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
      int dx = x + dirs[i];
      int dy = y + dirs[i + 1];

      if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
        continue;
      }

      if (visited[dx][dy] || mat[dx][dy] < mat[x][y]) {
        continue;
      }

      dfs(mat, visited, dx, dy);
    }
  }
};
// Runtime: 52 ms, faster than 36.47%
// Memory Usage: 22.5 MB, less than 24.34%

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> pac(m, vector<int>(n));
    vector<vector<int>> alt(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      bfs(matrix, pac, i, 0);
      bfs(matrix, alt, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
      bfs(matrix, pac, 0, j);
      bfs(matrix, alt, m - 1, j);
    }

    vector<vector<int>> ans;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pac[i][j] && alt[i][j]) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

  void bfs(const vector<vector<int>>& matrix,
           vector<vector<int>>& g,
           int x,
           int y) {
    int m = matrix.size();
    int n = matrix[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});

    vector<int> dirs = {0, 1, 0, -1, 0};

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto [x, y] = q.front();
        q.pop();

        g[x][y] = 1;

        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];

          if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
            continue;
          }

          if (g[dx][dy] || matrix[dx][dy] < matrix[x][y]) {
            continue;
          }

          g[dx][dy] = 1;
          q.push({dx, dy});
        }
      }
    }
  }
};
// Runtime: 56 ms, faster than 31.52%
// Memory Usage: 32.1 MB, less than 9.02%