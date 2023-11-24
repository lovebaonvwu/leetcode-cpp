class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    unordered_set<int> st;
    int n = nums.size();
    int i = n - 1;
    for (; i >= 0 && st.size() < k; --i) {
      if (nums[i] <= k) {
        st.insert(nums[i]);
      }
    }

    return n - 1 - i;
  }
};
// 9ms
// 19.34MB