class Solution {
 public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;

    for (auto n : unordered_set<int>(begin(nums), end(nums))) {
      ++cnt[__builtin_popcount(n)];
    }

    long long ans = 0;
    for (int i = 1; i <= 30; ++i) {
      for (int j = 1; j <= 30; ++j) {
        if (i + j >= k) {
          ans += cnt[i] * cnt[j];
        }
      }
    }

    return ans;
  }
};
// Runtime: 306 ms, faster than 50.00%
// Memory Usage: 86.8 MB, less than 50.00%
// 2022.7.29 at 奥盛大厦