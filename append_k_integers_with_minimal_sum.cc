class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    long long ans = 0;
    long long first = 1;
    for (int i = 0; i < nums.size() && k > 0; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      long long cnt = min(nums[i] - first, static_cast<long long>(k));
      long long second = first + cnt - 1;

      k -= cnt;

      ans += (first + second) * cnt / 2;

      first = nums[i] + 1;
    }

    if (k > 0) {
      long long second = first + k - 1;

      ans += (first + second) * k / 2;
    }

    return ans;
  }
};
// Runtime: 189 ms, faster than 79.85%
// Memory Usage: 66.3 MB, less than 43.74%
// 2022.4.24 at 奥盛大厦