class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<int>> ans(n - 2, vector<int>(n - 2));
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        int x = 0;
        for (auto dy : {-1, 0, 1}) {
          for (auto dx : {-1, 0, 1}) {
            x = max(x, grid[i + dy][j + dx]);
          }
        }

        ans[i - 1][j - 1] = x;
      }
    }

    return ans;
  }
};
// 14ms
// 11.43MB