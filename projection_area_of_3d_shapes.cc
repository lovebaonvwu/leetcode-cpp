class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    int top = 0, front = 0, side = 0, n = grid.size();

    for (int i = 0; i < n; ++i) {
      int yz = 0, xz = 0, xy = 0;

      for (int j = 0; j < n; ++j) {
        yz = max(yz, grid[i][j]);
        xz = max(xz, grid[j][i]);
        xy += grid[i][j] > 0;
      }

      side += yz;
      front += xz;
      top += xy;
    }

    return top + front + side;
  }
};
// Runtime: 7 ms, faster than 83.61%
// Memory Usage: 9.3 MB, less than 91.39%
// 2022.2.20 at 茗筑美嘉