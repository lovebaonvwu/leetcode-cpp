class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0.0;

    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        for (int k = j + 1; k < points.size(); ++k) {
          vector<int>& A = points[i];
          vector<int>& B = points[j];
          vector<int>& C = points[k];

          int xa = A[0], ya = A[1];
          int xb = B[0], yb = B[1];
          int xc = C[0], yc = C[1];

          ans = max(ans, 0.5 * abs(yc * xb + yb * xa + xc * ya - yc * xa -
                                   yb * xc - xb * ya));
        }
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 92.14%
// Memory Usage: 7.9 MB, less than 100.00%