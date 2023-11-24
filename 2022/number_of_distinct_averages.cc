class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    unordered_set<double> st;
    for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
      st.insert((nums[i] + nums[j]) / 2.0);
    }

    return st.size();
  }
};
// Runtime 8 ms
// Memory 7.1 MB
// 2022.11.19 at 茗筑美嘉