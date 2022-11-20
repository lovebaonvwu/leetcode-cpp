class Solution {
 public:
  int unequalTriplets(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          ans += nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k];
        }
      }
    }

    return ans;
  }
};
// Runtime 73 ms
// Memory 8.5 MB
// 2022.11.20 at 茗筑美嘉
