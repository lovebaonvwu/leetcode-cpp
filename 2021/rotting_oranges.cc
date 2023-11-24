class Solution {
  int rot(vector<vector<int>>& g, int i, int j, int d) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] != 1) {
      return 0;
    }

    g[i][j] = d + 3;

    return 1;
  }

 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int fresh = 0;

    for (auto& g : grid) {
      fresh += count_if(g.begin(), g.end(), [](int j) { return j == 1; });
    }

    int d = 0;

    while (fresh > 0) {
      int prev_fresh = fresh;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == d + 2) {
            fresh -= rot(grid, i + 1, j, d);
            fresh -= rot(grid, i - 1, j, d);
            fresh -= rot(grid, i, j + 1, d);
            fresh -= rot(grid, i, j - 1, d);
          }
        }
      }

      if (fresh == prev_fresh) {
        return -1;
      }

      ++d;
    }

    return d;
  }
};
// Runtime: 4 ms, faster than 95.10%
// Memory Usage: 8.8 MB, less than 100.00%

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    int fresh = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++fresh;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    int ans = 0;
    while (!q.empty() && fresh > 0) {
      int sz = q.size();

      while (sz > 0) {
        auto p = q.front();
        q.pop();
        --sz;

        for (auto& dir : dirs) {
          int x = p.first + dir[0];
          int y = p.second + dir[1];

          if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) {
            continue;
          }

          --fresh;
          grid[x][y] = 2;

          q.push({x, y});
        }
      }

      ++ans;
    }

    return fresh == 0 ? ans : -1;
  }

 private:
  vector<vector<int>> dirs{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
};
// Runtime: 4 ms, faster than 95.10%
// Memory Usage: 9.2 MB, less than 62.50%

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;

    while (true) {
      bool rot = false;

      vector<vector<int>> tmp = grid;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 2) {
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
              tmp[i - 1][j] = 2;
              rot = true;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
              tmp[i][j - 1] = 2;
              rot = true;
            }
            if (i + 1 < m && grid[i + 1][j] == 1) {
              tmp[i + 1][j] = 2;
              rot = true;
            }
            if (j + 1 < n && grid[i][j + 1] == 1) {
              tmp[i][j + 1] = 2;
              rot = true;
            }
          }
        }
      }

      if (!rot) {
        break;
      }

      grid = tmp;
      ++ans;
    }

    for (auto m : grid) {
      for (auto n : m) {
        if (n == 1) {
          return -1;
        }
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 60.61%
// Memory Usage: 9.5 MB, less than 43.75%