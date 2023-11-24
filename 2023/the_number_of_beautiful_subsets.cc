class Solution {
 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    int n = nums.size();
    function<void(int)> dp = [&](int i) {
      if (i == n) {
        ++ans;
        return;
      }

      if (!mp[nums[i] - k] && !mp[nums[i] + k]) {
        ++mp[nums[i]];
        dp(i + 1);
        --mp[nums[i]];
      }
      dp(i + 1);
    };

    dp(0);
    return ans - 1;
  }
};
// Runtime 1502 ms
// Memory 36.4 MB