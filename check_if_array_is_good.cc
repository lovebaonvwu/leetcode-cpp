class Solution {
 public:
  bool isGood(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int i = 0;
    for (int j = 1; i < n - 1; ++i, ++j) {
      if (nums[i] != j) {
        return false;
      }
    }

    return nums[i] == n - 1;
  }
};
// 4ms
// 22.48mb