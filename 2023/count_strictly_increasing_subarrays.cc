class Solution {
 public:
  long long countSubarrays(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    for (int i = 0, sum = 0; i < n; ++i) {
      if (i > 0 && nums[i] > nums[i - 1]) {
        ++sum;
      } else {
        sum = 1;
      }

      ans += sum;
    }

    return ans;
  }
};
// Runtime 141 ms
// Memory 75.7 MB
// 2023.1.17 at 奥盛大厦