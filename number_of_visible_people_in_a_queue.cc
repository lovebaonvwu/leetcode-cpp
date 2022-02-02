class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();

    vector<int> ans(n), stk;

    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[stk.back()] <= heights[i]) {
        ++ans[stk.back()];
        stk.pop_back();
      }

      if (!stk.empty()) {
        ++ans[stk.back()];
      }

      stk.push_back(i);
    }

    return ans;
  }
};
// Runtime: 144 ms, faster than 96.79%
// Memory Usage: 84.3 MB, less than 32.93%
// 2022.2.2 at 茗筑美嘉