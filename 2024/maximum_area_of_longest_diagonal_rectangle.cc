class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int ans = 0;

    int cur_max = 0;
    for (auto& d : dimensions) {
      int l = d[0];
      int w = d[1];

      int cur = l * l + w * w;
      if (cur > cur_max) {
        cur_max = cur;
        ans = l * w;
      } else if (cur == cur_max) {
        ans = max(ans, l * w);
      }
    }

    return ans;
  }
};
// 12 ms
// 25.21MB