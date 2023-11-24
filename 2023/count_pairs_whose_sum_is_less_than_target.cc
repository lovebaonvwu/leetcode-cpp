class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int ans = 0;
    while (i < j) {
      if (nums[i] + nums[j] >= target) {
        --j;
      } else {
        ans += j - i;
        ++i;
      }
    }

    return ans;
  }
};
// 4ms
// 20.40MB