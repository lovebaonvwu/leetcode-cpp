class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
      return 0;
    }

    sort(points.begin(), points.end());

    vector<vector<int>> section = {points[0]};

    int ans = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= section.back()[1] &&
          points[i][1] < section.back()[1]) {
        section.back()[1] = points[i][1];
      } else if (points[i][0] > section.back()[1]) {
        section.push_back(points[i]);
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 316 ms, faster than 19.56%
// Memory Usage: 26.6 MB, less than 100.00%

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
      return 0;
    }

    sort(points.begin(), points.end());

    int bound = points[0][1];

    int ans = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= bound && points[i][1] < bound) {
        bound = points[i][1];
      } else if (points[i][0] > bound) {
        bound = points[i][1];
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 292 ms, faster than 28.61%
// Memory Usage: 24.8 MB, less than 100.00%