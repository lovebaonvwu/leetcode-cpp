class Solution {
 public:
  int minDifference(vector<int>& nums) {
    sort(begin(nums), end(nums));

    function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
      if (k == 0)
        return nums[j] - nums[i];
      int ret = nums[j] - nums[i];
      if (i < j) {
        ret = min(ret, dfs(i, j - 1, k - 1));
        ret = min(ret, dfs(i + 1, j, k - 1));
      }

      return ret;
    };

    return dfs(0, nums.size() - 1, 3);
  }
};
// 73 ms
// 38.66 MB
