class Solution {
 public:
  int minimumChairs(string s) {
    int ans = 0;
    int cur = 0;
    for (auto e : s) {
      cur += e == 'E' ? 1 : -1;
      ans = max(ans, cur);
    }

    return ans;
  }
};
// 0 ms
// 7.98 MB