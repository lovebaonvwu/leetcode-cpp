class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    int ans = 0;

    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0) {
      if (grid[i][j] < 0) {
        ans += m - i;
        --j;
      } else {
        ++i;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 88.89%
// Memory Usage: 10.2 MB, less than 100.00%

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    int ans = 0;

    for (int i = m - 1; i >= 0 && grid[i].back() < 0; --i) {
      for (int j = n - 1; j >= 0 && grid[i][j] < 0; --j) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 88.89%
// Memory Usage: 10.2 MB, less than 100.00%

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    int ans = 0;

    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n) {
      if (grid[i][j] < 0) {
        ans += n - j;
        --i;
      } else {
        ++j;
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 66.67%
// Memory Usage: 10.2 MB, less than 100.00%

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      int lo = 0;
      int hi = n - 1;

      while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);

        if (grid[i][mid] >= 0) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }

      ans += n - lo;
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 66.67%
// Memory Usage: 10.3 MB, less than 100.00%

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] < 0) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 66.67%
// Memory Usage: 10.2 MB, less than 100.00%