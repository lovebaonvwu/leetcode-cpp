class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    int cnt = unordered_set<int>(nums.begin(), nums.end()).size();

    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      ++mp[nums[j]];
      if (mp.size() == cnt) {
        ans += (n - j);

        while (mp.size() == cnt) {
          --mp[nums[i]];
          if (mp[nums[i]] == 0) {
            mp.erase(nums[i]);
          } else {
            ans += (n - j);
          }
          ++i;
        }
      }
    }

    return ans;
  }
};
// 31ms
// 36.49mb