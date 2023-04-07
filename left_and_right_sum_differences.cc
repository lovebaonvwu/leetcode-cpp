class Solution {
 public:
  vector<int> leftRigthDifference(vector<int>& nums) {
    int total = accumulate(begin(nums), end(nums), 0);

    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0, cur = 0; i < n; ++i) {
      total -= nums[i];
      ans[i] = abs(cur - total);
      cur += nums[i];
    }

    return ans;
  }
};
// Runtime 3 ms
// Memory 10.9 MB
