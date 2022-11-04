class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    unordered_map<int, int> mp;
    int cnt = 0;

    for (auto n : nums) {
      int r = n % space;
      ++mp[r];

      cnt = max(cnt, mp[r]);
    }

    int ans = INT_MAX;
    for (auto n : nums) {
      if (mp[n % space] == cnt) {
        ans = min(ans, n);
      }
    }

    return ans;
  }
};
// Runtime: 402 ms, faster than 47.55%
// Memory Usage: 59 MB, less than 92.88%
// 2022.11.4 at 奥盛大厦