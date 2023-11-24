class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      int maxRow = 0;

      for (int i = 0; i < m; ++i) {
        maxRow = mat[i][mid] > mat[maxRow][mid] ? i : maxRow;
      }

      bool biggerThanLeft =
          (mid == 0) || (mat[maxRow][mid] > mat[maxRow][mid - 1]);
      bool biggerThanRight =
          (mid == n - 1) || (mat[maxRow][mid] > mat[maxRow][mid + 1]);

      if (biggerThanLeft && biggerThanRight) {
        return {maxRow, mid};
      } else if (biggerThanLeft) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return {-1, -1};
  }
};
// Runtime: 252 ms, faster than 5.23%
// Memory Usage: 46.1 MB, less than 89.81%
// 2021.7.13 at 奥盛大厦