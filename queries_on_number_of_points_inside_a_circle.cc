class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> ans;

    for (auto& q : queries) {
      int x = q[0];
      int y = q[1];
      int r = q[2];

      int cnt = 0;
      for (auto& p : points) {
        int x1 = p[0];
        int y1 = p[1];

        if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r) {
          ++cnt;
        }
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// Runtime: 117 ms, faster than 51.28%
// Memory Usage: 16.3 MB, less than 37.90%
// 2021.9.16 at 奥盛大厦