class Solution {
 public:
  int findClosestNumber(vector<int>& nums) {
    int ans = 0, gap = INT_MAX;

    for (auto n : nums) {
      int x = abs(n - 0);

      if (x < gap) {
        gap = x;
        ans = n;
      } else if (x == gap && n > ans) {
        ans = n;
      }
    }

    return ans;
  }
};
// Runtime: 41 ms, faster than 20.48%
// Memory Usage: 19.7 MB, less than 41.45%
// 2022.4.30 at 茗筑美嘉