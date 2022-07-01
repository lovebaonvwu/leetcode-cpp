class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    vector<int> cnt(2);

    for (int i = 0, lo = 0, hi = 0; i < nums.size(); ++i) {
      lo = i > 0 ? nums[i - 1] : 1001;
      hi = (i < nums.size() - 1) ? nums[i + 1] : 1001;

      cnt[i % 2] += max(0, nums[i] - min(lo, hi) + 1);
    }

    return min(cnt[0], cnt[1]);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.1 MB, less than 89.52%
// 2022.7.1 at 奥盛大厦