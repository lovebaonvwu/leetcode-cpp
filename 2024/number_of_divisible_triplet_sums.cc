class Solution {
 public:
  int divisibleTripletCount(vector<int>& nums, int d) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int target = (d - nums[i] % d) % d;
      ans += mp[target];
      for (int j = 0; j < i; ++j) {
        ++mp[(nums[j] + nums[i]) % d];
      }
    }

    return ans;
  }
};
// 70 ms
// 30.00 MB