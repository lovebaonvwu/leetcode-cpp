class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (is_sorted(nums.begin(), nums.end())) {
      return 0;
    }

    int n = nums.size();

    int mn = nums[n - 1];
    int mx = nums[0];

    int lo, hi;

    for (int i = 0; i < n; ++i) {
      mx = max(nums[i], mx);
      if (nums[i] < mx) {
        hi = i;
      }

      mn = min(nums[n - 1 - i], mn);
      if (nums[n - 1 - i] > mn) {
        lo = n - 1 - i;
      }
    }

    return hi - lo + 1;
  }
};
// Runtime: 36 ms, faster than 76.44%
// Memory Usage: 10.3 MB, less than 100.00%

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int lo = -1;
    int hi = -1;

    int prev = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] >= prev) {
        prev = nums[i];
        continue;
      }

      hi = i;

      auto it = upper_bound(nums.begin(), nums.begin() + i, nums[i]);
      int cur_lo = (int)(it - nums.begin());

      lo = lo == -1 ? cur_lo : min(cur_lo, lo);
    }

    return hi < 0 ? 0 : (hi - lo) + 1;
  }
};
// Runtime: 44 ms, faster than 46.66%
// Memory Usage: 10.4 MB, less than 100.00%