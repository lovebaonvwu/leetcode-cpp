class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    map<pair<int, int>, vector<pair<int, int>>> mp;

    for (int i = 0, n = points.size(); i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          auto& p1 = points[i];
          auto& p2 = points[j];

          int dx = p1[0] - p2[0];
          int dy = p1[1] - p2[1];

          mp[{dx, dy}].push_back({i, j});
        }
      }
    }

    double ans = -1;

    for (auto& m : mp) {
      for (int i = 0, n = m.second.size(); i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          auto& a = points[m.second[i].first];
          auto& b = points[m.second[i].second];
          auto& c = points[m.second[j].first];

          int dx1 = a[0] - b[0];
          int dy1 = a[1] - b[1];
          int dx2 = a[0] - c[0];
          int dy2 = a[1] - c[1];

          if (dx1 * dx2 + dy1 * dy2 != 0) {
            continue;
          }

          int len1 = dx1 * dx1 + dy1 * dy1;
          int len2 = dx2 * dx2 + dy2 * dy2;

          double area = sqrt(len1) * sqrt(len2);

          ans = ans == -1 ? area : min(ans, area);
        }
      }
    }

    return max<double>(0, ans);
  }
};
// Runtime: 118 ms, faster than 44.97%
// Memory Usage: 25.1 MB, less than 33.73%
// 2021.10.19 at 奥盛大厦