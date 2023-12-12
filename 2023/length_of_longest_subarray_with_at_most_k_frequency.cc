class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int ans = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      ++freq[nums[i]];
      while (freq[nums[i]] > k) {
        --freq[nums[j++]];
      }

      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};
// 212ms
// 144.67MB