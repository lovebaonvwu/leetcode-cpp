class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    int a = INT_MAX;
    int b = INT_MAX;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < a) {
        b = a;
        a = nums[i];
      } else if (nums[i] < b) {
        b = nums[i];
      }
    }

    return nums[0] + a + b;
  }
};
// 11ms
// 29.30MB