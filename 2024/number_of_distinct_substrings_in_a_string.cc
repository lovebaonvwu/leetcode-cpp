class Solution {
 public:
  int countDistinct(string s) {
    unordered_set<string> st;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        st.insert(s.substr(i, j));
      }
    }

    return st.size();
  }
};
// 2781 ms
// 610.67 MB