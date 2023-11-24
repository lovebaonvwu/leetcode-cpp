class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for (int i = 1; i < n - 1; ++i) {
      left[i] = min(left[i - 1], nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      right[i] = min(right[i + 1], nums[i]);
    }

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; ++i) {
      if (left[i - 1] < nums[i] && right[i + 1] < nums[i]) {
        ans = min(ans, nums[i] + left[i - 1] + right[i + 1]);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// 123ms
// 80.61MB