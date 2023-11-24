class Solution {
 public:
  int shortestSequence(vector<int>& rolls, int k) {
    int ans = 0;
    unordered_set<int> st;

    for (auto r : rolls) {
      st.insert(r);
      if (st.size() == k) {
        ++ans;
        st.clear();
      }
    }

    return ans + 1;
  }
};
// Runtime: 402 ms, faster than 52.79%
// Memory Usage: 107.9 MB, less than 85.90%
// 2022.8.4 at 奥盛大厦