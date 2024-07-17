class Solution {
 public:
  int longestRepeatingSubstring(string s) {
    unordered_set<string> st;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= min(j, n - i); ++j) {
        string t = s.substr(i, j);
        if (st.find(t) != st.end()) {
          ans = max(ans, j);
        }

        st.insert(t);
      }
    }

    return ans;
  }
};
// 3933 ms
// 777.34 MB