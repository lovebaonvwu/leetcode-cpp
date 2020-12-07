class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;

    for (int step = 1; ans.size() < R * C;) {
      for (int i = 0; i < step; ++i) {
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
        ++c0;
      }

      for (int i = 0; i < step; ++i) {
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
        ++r0;
      }

      ++step;

      for (int i = 0; i < step; ++i) {
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
        --c0;
      }

      for (int i = 0; i < step; ++i) {
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ans.push_back({r0, c0});
        }
        --r0;
      }

      ++step;
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 46.42%
// Memory Usage: 12.6 MB, less than 35.28%

class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> ans;

    for (int step = 1, d = 0; ans.size() < R * C;) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < step; ++j) {
          if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
            ans.push_back({r0, c0});
          }

          r0 += dir[d][0];
          c0 += dir[d][1];
        }

        d = (d + 1) % 4;
      }
      ++step;
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 81.70%
// Memory Usage: 12.6 MB, less than 35.28%