class Solution {
  int m;
  int n;

 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();

    if ((m + n) % 2 == 0) {
      return false;
    }

    return dfs(grid, 0, 0, 0);
  }

  bool dfs(vector<vector<char>>& g, int x, int y, int cnt) {
    if (x == m || y == n) {
      return false;
    }

    cnt += g[x][y] == '(' ? 1 : -1;

    if (cnt < 0) {
      return false;
    }

    if ((x == m - 1) && (y == n - 1) && (cnt == 0)) {
      return true;
    }

    return dfs(g, x + 1, y, cnt) || dfs(g, x, y + 1, cnt);
  }
};
// Time Limit Exceeded
// 2022.5.10 at 奥盛大厦

class Solution {
  int m;
  int n;
  int visited[101][101][101];

 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();

    if ((m + n) % 2 == 0) {
      return false;
    }

    return dfs(grid, 0, 0, 0);
  }

  bool dfs(vector<vector<char>>& g, int x, int y, int cnt) {
    if (x == m || y == n) {
      return false;
    }

    cnt += g[x][y] == '(' ? 1 : -1;

    if (cnt < 0 || visited[x][y][cnt]) {
      return false;
    }

    visited[x][y][cnt] = 1;

    if ((x == m - 1) && (y == n - 1) && (cnt == 0)) {
      return true;
    }

    return dfs(g, x + 1, y, cnt) || dfs(g, x, y + 1, cnt);
  }
};
// Runtime: 54 ms, faster than 99.33%
// Memory Usage: 17.7 MB, less than 76.49%
// 2022.5.10 at 奥盛大厦