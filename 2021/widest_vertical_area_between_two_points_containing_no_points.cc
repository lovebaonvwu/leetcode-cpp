class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    int ans = points[1][0] - points[0][0];

    for (int i = 2; i < points.size(); ++i) {
      ans = max(ans, points[i][0] - points[i - 1][0]);
    }

    return ans;
  }
};
// Runtime: 284 ms, faster than 81.01%
// Memory Usage: 66.3 MB, less than 89.66%