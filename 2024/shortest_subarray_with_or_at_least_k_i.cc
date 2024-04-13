class Solution {
 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    for (int l = 1; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        int sum = 0;
        for (int j = 0; j < l; ++j) {
          sum |= nums[i + j];
        }

        if (sum >= k) {
          return l;
        }
      }
    }

    return -1;
  }
};
// 3 ms
// 25.91 MB