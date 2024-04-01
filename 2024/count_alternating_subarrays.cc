class Solution {
 public:
  long long countAlternatingSubarrays(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    for (int i = 0, j = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        j = i;
      }

      ans += i - j + 1;
    }

    return ans;
  }
};
// 77 ms
// 116.13 MB