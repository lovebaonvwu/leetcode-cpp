class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0, sum = 0; i < nums.size(); ++i) {
      sum += nums[i];

      int rem = sum % k;
      if (mp.find(rem) != mp.end() && i - mp[rem] > 1) {
        return true;
      }

      mp.insert({rem, i});
    }

    return false;
  }
};
// Runtime: 208 ms, faster than 72.47%
// Memory Usage: 96.5 MB, less than 77.04%
// 2022.5.9 at 奥盛大厦