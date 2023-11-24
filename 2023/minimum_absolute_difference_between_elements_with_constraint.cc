class Solution {
 public:
  int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> st;
    int ans = INT_MAX;
    for (int i = x; i < nums.size(); ++i) {
      st.insert(nums[i - x]);
      auto it = st.upper_bound(nums[i]);
      if (it != st.begin()) {
        ans = min(ans, nums[i] - *prev(it));
      }
      if (it != st.end()) {
        ans = min(ans, *it - nums[i]);
      }
    }

    return ans;
  }
};
// 195ms
// 118.16mb