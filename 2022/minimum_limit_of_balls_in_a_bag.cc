class Solution {
 public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int lo = 1, hi = 1e9;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      int op = 0;

      for (auto n : nums) {
        op += (n - 1) / mid;
      }

      if (op > maxOperations) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }
};
// Runtime: 242 ms, faster than 66.62%
// Memory Usage: 56 MB, less than 79.05%
// 2022.2.5 at 茗筑美嘉