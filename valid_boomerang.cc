class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    auto& a = points[0];
    auto& b = points[1];
    auto& c = points[2];

    return (b[1] - a[1]) * (c[0] - a[0]) != (c[1] - a[1]) * (b[0] - a[0]);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 10.2 MB, less than 35.23%