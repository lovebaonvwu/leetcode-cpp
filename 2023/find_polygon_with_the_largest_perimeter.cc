class Solution {
 public:
  long long largestPerimeter(vector<int>& nums) {
    sort(begin(nums), end(nums));
    long long ans = -1LL;

    int n = nums.size();
    long long sum = nums[0] + nums[1];
    for (int i = 2; i < n; ++i) {
      if (nums[i] < sum) {
        ans = sum + nums[i];
      }

      sum += nums[i];
    }

    return ans;
  }
};
// 151ms
// 79.02MB