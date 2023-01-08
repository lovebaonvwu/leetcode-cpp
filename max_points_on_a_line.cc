class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      auto& p1 = points[i];
      map<pair<int, int>, int> mp;
      int samePoint = 1;
      int maxPoint = 0;
      for (int j = i + 1; j < n; ++j) {
        auto& p2 = points[j];
        if (p1 == p2) {
          ++samePoint;
        } else {
          maxPoint = max(maxPoint, ++mp[slope(p1, p2)]);
        }
      }
      ans = max(ans, maxPoint + samePoint);
    }

    return ans;
  }

 private:
  pair<int, int> slope(vector<int>& p1, vector<int>& p2) {
    int dy = p2[1] - p1[1];
    int dx = p2[0] - p1[0];

    if (dy == 0) {
      return {p2[1], 0};
    }

    if (dx == 0) {
      return {0, p2[0]};
    }

    int g = gcd(dy, dx);
    return {dy / g, dx / g};
  }

  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return gcd(b, a % b);
  }
};
// Runtime 34 ms
// Memory 12.5 MB
// 2023.1.8 at 奥盛大厦