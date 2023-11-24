class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      bool champin = true;
      for (int j = 0; j < n; ++j) {
        if (i != j && grid[i][j] == 0) {
          champin = false;
          break;
        }
      }

      if (champin) {
        ans = i;
        break;
      }
    }

    return ans;
  }
};
// 52ms
// 36.68MB