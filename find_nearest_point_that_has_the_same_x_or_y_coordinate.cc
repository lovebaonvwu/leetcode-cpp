class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int d = INT_MAX;
    int ans = -1;

    for (int i = 0; i < points.size(); ++i) {
      int a = points[i][0];
      int b = points[i][1];

      if (a == x || y == b) {
        if (abs(x - a) + abs(y - b) < d) {
          ans = i;
          d = abs(x - a) + abs(y - b);
        }
      }
    }

    return ans;
  }
};
// Runtime: 156 ms, faster than 65.18%
// Memory Usage: 59.3 MB, less than 95.12%
// 2021.8.17 at 奥盛大厦