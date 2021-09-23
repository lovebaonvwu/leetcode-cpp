class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    multiset<int> st;
    int j = 0, ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      st.insert(nums[i]);

      while (!st.empty() && *st.rbegin() - *st.begin() > limit) {
        st.erase(st.find(nums[j++]));
      }

      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};
// Runtime: 196 ms, faster than 35.55%
// Memory Usage: 78.6 MB, less than 26.26%
// 2021.9.23 at 奥盛大厦