class Solution {
 public:
  int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();

    vector<int> rmin(n, nums.back());

    for (int i = n - 2; i >= 0; --i) {
      rmin[i] = min(nums[i], rmin[i + 1]);
    }

    int ans = 0;

    int lmax = nums[0];

    for (int i = 1; i < n - 1; ++i) {
      if (nums[i] > lmax && nums[i] < rmin[i + 1]) {
        ans += 2;
      } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
        ans += 1;
      }

      lmax = max(lmax, nums[i]);
    }

    return ans;
  }
};
// Runtime: 140 ms, faster than 87.64%
// Memory Usage: 85.3 MB, less than 59.14%
// 2021.11.25 at 奥盛大厦