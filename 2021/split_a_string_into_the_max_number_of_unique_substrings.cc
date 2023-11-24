class Solution {
  unordered_set<string> st;
  int ans = 0;

 public:
  int maxUniqueSplit(string s) {
    dfs(s, 0);

    return ans;
  }

  void dfs(string& s, int start) {
    if (start == s.size()) {
      return;
    }

    for (int i = start; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        string t = s.substr(i, j - i + 1);

        if (st.count(t) == 0) {
          st.insert(t);
          ans = max(ans, (int)st.size());
          dfs(s, j + 1);
          st.erase(t);
        }
      }
    }
  }
};
// Time Limit Exceeded

class Solution {
  unordered_set<string> st;
  int ans = 0;

 public:
  int maxUniqueSplit(string s) {
    dfs(s, 0);

    return ans;
  }

  void dfs(string& s, int start) {
    if (start == s.size()) {
      ans = max(ans, (int)st.size());
      return;
    }

    for (int i = start; i < s.size(); ++i) {
      string sub = s.substr(start, i - start + 1);

      if (st.count(sub) == 0) {
        st.insert(sub);
        dfs(s, i + 1);
        st.erase(sub);
      }
    }
  }
};
// Runtime: 560 ms, faster than 47.04%
// Memory Usage: 44.3 MB, less than 49.18%