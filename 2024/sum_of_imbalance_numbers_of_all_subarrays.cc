class Solution {
 public:
  int sumImbalanceNumbers(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      unordered_set<int> st{nums[i]};
      int cnt = 0;
      for (int j = i + 1; j < n; ++j) {
        if (st.find(nums[j]) == st.end()) {
          if (st.count(nums[j] - 1) && st.count(nums[j] + 1)) {
            --cnt;
          } else if (!st.count(nums[j] - 1) && !st.count(nums[j] + 1)) {
            ++cnt;
          }
        }

        st.insert(nums[j]);

        ans += cnt;
      }
    }

    return ans;
  }
};
// 351 ms
// 139.89 MB