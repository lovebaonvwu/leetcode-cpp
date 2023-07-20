class Solution {
 public:
  int minimumBeautifulSubstrings(string s) {
    unordered_set<string> st;
    st.insert("1");
    st.insert("101");
    st.insert("11001");
    st.insert("1111101");
    st.insert("1001110001");
    st.insert("110000110101");
    st.insert("11110100001001");

    function<int(const string&, int)> dp = [&](const string& prev,
                                               int i) -> int {
      string new_string = prev + s[i];
      if (i == s.size() - 1) {
        if (st.find(new_string) != st.end()) {
          return 1;
        } else {
          return INT_MAX / 2;
        }
      }

      if (!prev.empty() && prev[0] == '0') {
        return INT_MAX / 2;
      }

      int res = INT_MAX / 2;
      if (st.find(new_string) != st.end()) {
        res = 1 + dp("", i + 1);
      }

      return res = min(res, dp(new_string, i + 1));
    };

    string prev = "";
    int ans = dp(prev, 0);
    return ans >= INT_MAX / 2 ? -1 : ans;
  }
};
// 11ms
// 6.37mb