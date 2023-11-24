class Solution {
  int m;
  int n;

 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    m = grid2.size();
    n = grid2[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));
    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j] == 1 && !visited[i][j]) {
          queue<pair<int, int>> q;

          q.push({i, j});

          bool isSub = true;
          while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            visited[r][c] = true;

            if (grid1[r][c] == 0) {
              isSub = false;
            }

            int dirs[] = {0, -1, 0, 1, 0};

            for (int k = 0; k < 4; ++k) {
              auto dr = r + dirs[k];
              auto dc = c + dirs[k + 1];

              if (dr < 0 || dr >= m || dc < 0 || dc >= n) {
                continue;
              }

              if (grid2[dr][dc] == 0) {
                continue;
              }

              if (visited[dr][dc]) {
                continue;
              }

              q.push({dr, dc});
            }
          }

          ans += isSub;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  int m;
  int n;

 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    m = grid2.size();
    n = grid2[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j]) {
          if (dfs(grid1, grid2, i, j)) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }

  bool dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n) {
      return true;
    }

    if (g2[r][c] == 0) {
      return true;
    }

    g2[r][c] = 0;

    bool ret = true;

    ret &= dfs(g1, g2, r - 1, c);
    ret &= dfs(g1, g2, r + 1, c);
    ret &= dfs(g1, g2, r, c - 1);
    ret &= dfs(g1, g2, r, c + 1);

    return g1[r][c] & ret;
  }
};
// Runtime: 264 ms, faster than 94.52%
// Memory Usage: 88.4 MB, less than 90.52%