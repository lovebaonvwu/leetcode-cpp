class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 1; i < points.size(); ++i) {
      ans += max(abs(points[i][0] - points[i - 1][0]),
                 abs(points[i][1] - points[i - 1][1]));
    }
    return ans;
  }
};
// Runtime: 8 ms, faster than 90.18%
// Memory Usage: 10.2 MB, less than 100.00%

class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    if (points.size() == 1) {
      return 0;
    }

    int ans = 0;

    for (int i = 1; i < points.size(); ++i) {
      ans += max(abs(points[i][0] - points[i - 1][0]),
                 abs(points[i][1] - points[i - 1][1]));
    }
    return ans;
  }
};
// Runtime: 8 ms, faster than 90.18%
// Memory Usage: 10.1 MB, less than 100.00%