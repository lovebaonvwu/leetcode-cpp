class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();

    vector<vector<int>> ans;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (land[i][j] == 1) {
          int c = j;
          while (c < n && land[i][c] == 1) {
            ++c;
          }

          int r = i;
          while (r < m && land[r][j] == 1) {
            ++r;
          }

          ans.push_back({i, j, r - 1, c - 1});

          for (int x = i; x < r; ++x) {
            for (int y = j; y < c; ++y) {
              land[x][y] = 2;
            }
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 124 ms, faster than 100.00%
// Memory Usage: 56.4 MB, less than 100.00%
// 2021.9.6 at 奥盛大厦

class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();

    vector<vector<int>> ans;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (land[i][j] == 1 && (j == 0 || land[i][j - 1] == 0) &&
            (i == 0 || land[i - 1][j] == 0)) {
          int c = j;
          while (c < n && land[i][c] == 1) {
            ++c;
          }

          int r = i;
          while (r < m && land[r][j] == 1) {
            ++r;
          }

          ans.push_back({i, j, r - 1, c - 1});
        }
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 100.00%
// Memory Usage: 56.4 MB, less than 100.00%
// 2021.9.6 at 奥盛大厦