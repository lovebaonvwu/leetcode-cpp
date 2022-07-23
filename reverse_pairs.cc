class Solution {
  int ans = 0;

 public:
  int reversePairs(vector<int>& nums) {
    vector<int> sorted = nums;

    dfs(nums, sorted, 0, nums.size() - 1);

    return ans;
  }

  void dfs(vector<int>& nums, vector<int>& sorted, int lo, int hi) {
    if (lo >= hi) {
      return;
    }

    int md = lo + (hi - lo) / 2;
    dfs(nums, sorted, lo, md);
    dfs(nums, sorted, md + 1, hi);

    for (int i = md + 1; i <= hi; ++i) {
      auto it = upper_bound(sorted.begin() + lo, sorted.begin() + md + 1,
                            nums[i] * 1LL * 2);

      ans += (sorted.begin() + md + 1) - it;
    }

    sort(sorted.begin() + lo, sorted.begin() + hi + 1);
  }
};
// Runtime: 806 ms, faster than 54.87%
// Memory Usage: 46.9 MB, less than 72.02%
// 2022.7.23 at 茗筑美嘉