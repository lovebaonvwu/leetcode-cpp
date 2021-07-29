class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(2 * n);

    for (int i = 0; i < n; ++i) {
      ans[i] = nums[i];
      ans[i + n] = nums[i];
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 86.86%
// Memory Usage: 12.4 MB, less than 94.69%