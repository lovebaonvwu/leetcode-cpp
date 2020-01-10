class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    int ans = 0;
    int sum = 0;

    mp[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans += mp[sum - k];

      ++mp[sum];
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 26.36%
// Memory Usage: 18.1 MB, less than 22.67%

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
      int sum = nums[i];

      if (sum == k) {
        ++ans;
      }

      for (int j = i + 1; j < nums.size(); ++j) {
        sum += nums[j];

        if (sum == k) {
          ++ans;
        }
      }
    }

    return nums[nums.size() - 1] == k ? ++ans : ans;
  }
};
// Runtime: 488 ms, faster than 18.09%
// Memory Usage: 9.9 MB, less than 98.67%