class Solution {
 public:
  int medianOfUniquenessArray(vector<int>& nums) {
    long long n = nums.size();
    function<long long(int)> count = [&](int k) -> long long {
      unordered_map<int, int> cnt;
      long long ret = 0;
      for (long long i = 0, j = 0; i < n; ++i) {
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

    long long total = n + (1 + n - 1) * (n - 1) / 2;

    int lo = 1, hi = n;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      long long cnt = count(md);
      if (cnt >= (total + 1) / 2) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }
};
// 1612 ms
// 371.85 MB