class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int k = 0;
        for (; k < n; ++k) {
          if (grid[i][k] != grid[k][j]) {
            break;
          }
        }

        ans += k == n;
      }
    }

    return ans;
  }
};
// Runtime: 484 ms, faster than 66.67%
// Memory Usage: 23.5 MB, less than 100.00%
// 2022.7.25 at 奥盛大厦

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> mp;

    for (int j = 0; j < n; ++j) {
      vector<int> col;

      for (int i = 0; i < n; ++i) {
        col.push_back(grid[i][j]);
      }

      ++mp[move(col)];
    }

    int ans = 0;
    for (auto& row : grid) {
      ans += mp[row];
    }

    return ans;
  }
};
// Runtime: 126 ms, faster than 66.67%
// Memory Usage: 31.8 MB, less than 33.33%
// 2022.7.25 at 奥盛大厦