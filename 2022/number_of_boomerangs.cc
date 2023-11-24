class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); ++i) {
      unordered_map<int, int> mp;

      for (int j = 0; j < points.size(); ++j) {
        int key = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
        key += (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);

        ++mp[key];
      }

      for (auto& [k, v] : mp) {
        ans += v * (v - 1);
      }
    }

    return ans;
  }
};
// Runtime: 488 ms, faster than 76.11%
// Memory Usage: 124.4 MB, less than 52.39%
// 2022.1.7 at 奥盛大厦