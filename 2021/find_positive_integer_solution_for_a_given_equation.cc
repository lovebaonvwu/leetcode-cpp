/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> ans;

    for (int i = 1; i <= 1000; ++i) {
      int lo = 1, hi = 1000;

      while (lo <= hi) {
        int md = lo + (hi - lo) / 2;

        int val = customfunction.f(i, md);

        if (val == z) {
          ans.push_back({i, md});
          break;
        } else if (val < z) {
          lo = md + 1;
        } else {
          hi = md - 1;
        }
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 25.67%
// Memory Usage: 6.2 MB, less than 83.91%

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> ans;

    for (int i = 1, j = 1000; i <= 1000; ++i) {
      while (j > 1 && customfunction.f(i, j) > z) {
        --j;
      }

      if (customfunction.f(i, j) == z) {
        ans.push_back({i, j});
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%