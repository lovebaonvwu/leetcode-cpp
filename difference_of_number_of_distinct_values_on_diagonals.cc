class Solution {
 public:
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        unordered_set<int> tl;
        int r = i - 1, c = j - 1;

        while (r >= 0 && c >= 0) {
          tl.insert(grid[r--][c--]);
        }

        unordered_set<int> br;
        r = i + 1, c = j + 1;
        while (r < m && c < n) {
          br.insert(grid[r++][c++]);
        }

        ans[i][j] = abs((int)tl.size() - (int)br.size());
      }
    }

    return ans;
  }
};
// Runtime 253 ms
// Memory 78.7 MB