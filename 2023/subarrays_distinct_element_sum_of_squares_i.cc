class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 1; i + j <= n; ++j) {
        unordered_set<int> st(nums.begin() + i, nums.begin() + i + j);
        ans += st.size() * st.size();
      }
    }

    return ans;
  }
};
// 849ms
// 299.89MB