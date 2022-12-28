class Solution {
 public:
  int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int p = find(nums.begin(), nums.end(), k) - nums.begin();

    for (int i = p, sum = 0; i < nums.size(); ++i) {
      sum += nums[i] == k ? 0 : nums[i] > k ? 1 : -1;
      ++mp[sum];
    }

    int ans = 0;
    for (int i = p, sum = 0; i >= 0; --i) {
      sum += nums[i] == k ? 0 : nums[i] > k ? 1 : -1;
      ans += mp[-sum] + mp[-sum + 1];
    }

    return ans;
  }
};
// Runtime 99 ms
// Memory 52.7 MB
// 2022.12.28 at 奥盛大厦