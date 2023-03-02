class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return min({nums[nums.size() - 3] - nums[0],
                nums[nums.size() - 1] - nums[2],
                nums[nums.size() - 2] - nums[1]});
  }
};
// Runtime 102 ms
// Memory 34.3 MB
// 2023.3.2 at 奥盛大厦