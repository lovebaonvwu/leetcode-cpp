class Solution {
 public:
  int minimizedStringLength(string s) {
    unordered_set<char> st(s.begin(), s.end());

    return st.size();
  }
};
// Runtime 37 ms
// Memory 13.1 MB