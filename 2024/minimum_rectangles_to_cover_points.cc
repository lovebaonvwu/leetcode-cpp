class Solution {
 public:
  int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    sort(begin(points), end(points));

    int ans = 0;
    int n = points.size();
    for (int i = 0; i < n;) {
      int j = i;
      for (; j < n; ++j) {
        if (points[j][0] - points[i][0] > w) {
          ++ans;
          break;
        }
      }
      i = j;
    }

    return ans + 1;
  }
};
// 251 ms
// 118.21 MB