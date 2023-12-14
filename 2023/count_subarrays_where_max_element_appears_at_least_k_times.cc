class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int target = *max_element(begin(nums), end(nums));
    long long ans = 0;
    int n = nums.size();
    for (int i = 0, j = 0; i < n; ++i) {
      ++cnt[nums[i]];
      while (cnt[target] >= k) {
        ans += n - i;
        --cnt[nums[j++]];
      }
    }

    return ans;
  }
};
// 276ms
// 145.72MB