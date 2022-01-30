class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> st(nums.begin(), nums.end());

    while (st.find(original) != st.end()) {
      original *= 2;
    }

    return original;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 12.3 MB, less than 10.00%
// 2022.1.30 at 茗筑美嘉