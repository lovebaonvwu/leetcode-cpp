class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int ans = n;

    for (int i = 0, j = 0; i < nums.size(); ++i) {
      while (j < nums.size() && nums[j] <= nums[i] + (n - 1)) {
        ++j;
      }

      ans = min(ans, n - (j - i));
    }

    return ans;
  }
};
// Runtime: 219 ms, faster than 92.43%
// Memory Usage: 64.3 MB, less than 54.34%
// 2022.6.28 at 奥盛大厦