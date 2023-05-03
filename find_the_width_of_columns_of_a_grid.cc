class Solution {
 public:
  vector<int> findColumnWidth(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> ans;

    for (int j = 0; j < n; ++j) {
      int maxlen = 0;
      for (int i = 0; i < m; ++i) {
        int len = grid[i][j] < 0 || grid[i][j] == 0;
        int k = grid[i][j] < 0 ? -grid[i][j] : grid[i][j];
        while (k > 0) {
          ++len;
          k /= 10;
        }

        maxlen = max(maxlen, len);
      }

      ans.push_back(maxlen);
    }

    return ans;
  }
};
// Runtime 27 ms
// Memory 10.4 MB