class Solution {
  int ans = INT_MAX;
  int m;
  int n;

  vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();

    vector<vector<int>> visited(m, vector<int>(n));

    dfs(heights, visited, 0, 0, 0, heights[0][0]);

    return ans;
  }

  void dfs(vector<vector<int>>& h,
           vector<vector<int>> v,
           int x,
           int y,
           int e,
           int prev) {
    if (x < 0 || y < 0 || x == m || y == n || v[x][y]) {
      return;
    }

    e = max(e, abs(h[x][y] - prev));

    if (x == m - 1 && y == n - 1) {
      ans = min(ans, e);
      return;
    }

    v[x][y] = 1;

    for (auto& dir : dirs) {
      dfs(h, v, x + dir[0], y + dir[1], e, h[x][y]);
    }
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    int lo = 0;
    int hi = 1000000;
    int visited[100][100];

    while (lo < hi) {
      int weight = lo + (hi - lo) / 2;

      memset(visited, 0, sizeof(visited));

      if (dfs(0, 0, m, n, weight, visited, heights)) {
        hi = weight;
      } else {
        lo = weight + 1;
      }
    }

    return lo;
  }

  bool dfs(int x,
           int y,
           int m,
           int n,
           int w,
           int v[100][100],
           vector<vector<int>>& h) {
    if (x == m - 1 && y == n - 1) {
      return true;
    }

    v[x][y] = 1;

    int dirs[5] = {0, 1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) {
      int dx = x + dirs[i];
      int dy = y + dirs[i + 1];

      if (dx < 0 || dy < 0 || dx == m || dy == n || v[dx][dy]) {
        continue;
      }

      if (abs(h[dx][dy] - h[x][y]) > w) {
        continue;
      }

      if (dfs(dx, dy, m, n, w, v, h)) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 132 ms, faster than 96.87%
// Memory Usage: 17.3 MB, less than 95.63%