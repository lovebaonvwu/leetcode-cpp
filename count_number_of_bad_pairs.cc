class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) {
      return 0;
    }

    long long total = (1LL + (n - 1)) * (n - 1) / 2;

    unordered_map<int, long long> cnt;

    long long same = 0;
    for (int i = 0; i < n; ++i) {
      int key = nums[i] - i;
      same += cnt[key];
      ++cnt[key];
    }

    return total - same;
  }
};
// Runtime: 237 ms, faster than 100.00%
// Memory Usage: 88.6 MB, less than 100.00%
// 2022.8.9 at 奥盛大厦