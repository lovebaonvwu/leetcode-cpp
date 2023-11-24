class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int l = 0, r = n - 1, mod = 1e9 + 7;

    vector<int> pows(n, 1);

    for (int i = 1; i < n; ++i) {
      pows[i] = pows[i - 1] * 2 % mod;
    }

    int ans = 0;
    while (l <= r) {
      if (nums[l] + nums[r] <= target) {
        ans = (ans + pows[r - l]) % mod;
        ++l;
      } else {
        --r;
      }
    }

    return ans;
  }
};
// Runtime 143 ms
// Memory 49.8 MB