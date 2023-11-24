class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    unordered_set<int> st;
    int m = strs.size();
    int n = strs[0].size();

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (st.count(j) || strs[i - 1][j] == strs[i][j]) {
          continue;
        }
        if (strs[i - 1][j] > strs[i][j]) {
          st.insert(j);
          i = 0;
        }
        break;
      }
    }

    return st.size();
  }
};
// 7ms
// 10.29MB