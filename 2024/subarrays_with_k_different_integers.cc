class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    function<int(int)> slidingWindowAtMostK = [&](int k) -> int {
      unordered_map<int, int> cnt;
      int ret = 0;
      for (int i = 0, j = 0; i < n; ++i) {
        ++cnt[nums[i]];
        while (cnt.size() > k) {
          --cnt[nums[j]];
          if (cnt[nums[j]] == 0)
            cnt.erase(nums[j]);
          ++j;
        }

        ret += i - j + 1;
      }

      return ret;
    };

    return slidingWindowAtMostK(k) - slidingWindowAtMostK(k - 1);
  }
};
// 114 ms
// 49.87 MB