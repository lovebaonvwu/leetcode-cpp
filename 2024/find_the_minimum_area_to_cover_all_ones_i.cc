class Solution {
 public:
  int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int top = m;
    int bottom = 0;
    int left = n;
    int right = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0)
          continue;
        top = min(top, i);
        bottom = max(bottom, i);
        left = min(left, j);
        right = max(right, j);
      }
    }

    return (bottom - top + 1) * (right - left + 1);
  }
};
// 263 ms
// 132.14 MB