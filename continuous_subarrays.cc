class Solution {
 public:
  long long continuousSubarrays(vector<int>& nums) {
    map<int, int> mp;
    long long ans = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      mp[nums[i]] = i;
      for (auto it = mp.begin(); nums[i] - it->first > 2; ++it) {
        j = max(j, it->second + 1);
        mp.erase(it);
      }
      for (auto it = prev(mp.end()); it->first - nums[i] > 2; --it) {
        j = max(j, it->second + 1);
        mp.erase(it);
      }

      ans += i - j + 1;
    }

    return ans;
  }
};
// 112ms
// 106.99mb