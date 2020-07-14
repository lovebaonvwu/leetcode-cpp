class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int ans = 0;

    for (int i = 0, n = nums.size(); i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] == nums[i]) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 100.00%

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int mp[101] = {};

    int ans = 0;
    for (auto n : nums) {
      ans += mp[n]++;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.2 MB, less than 100.00%