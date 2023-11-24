class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    long long ans = 0, sum = 0;
    unordered_map<int, int> mp;
    unordered_set<int> st;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ++mp[nums[i]];
      if (mp[nums[i]] > 1) {
        st.insert(nums[i]);
      }

      if (i >= k) {
        sum -= nums[i - k];
        --mp[nums[i - k]];
        if (mp[nums[i - k]] < 2) {
          st.erase(nums[i - k]);
        }
      }

      if (i >= k - 1 && st.empty()) {
        ans = max(ans, sum);
      }
    }

    return ans;
  }
};
// Runtime 617 ms
// Memory 93.9 MB
// 2022.11.7 at 奥盛大厦