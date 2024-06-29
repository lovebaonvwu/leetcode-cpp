class Solution {
 public:
  double minimumAverage(vector<int>& nums) {
    sort(begin(nums), end(nums));

    double ans = INT_MAX;
    int n = nums.size();

    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      ans = min(ans, 1.0 * (nums[i] + nums[j]) / 2);
    }

    return ans;
  }
};
// 8 ms
// 25.07 MB
