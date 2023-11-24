class Solution {
 public:
  int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ans = 1, prev = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - prev > k) {
        ++ans;
        prev = nums[i];
      }
    }

    return ans;
  }
};
// Runtime: 243 ms, faster than 100.00%
// Memory Usage: 83.1 MB, less than 50.00%
// 2022.6.6 at 奥盛大厦