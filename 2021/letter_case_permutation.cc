class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    unordered_set<string> st;

    st.insert(S);

    vector<string> ans;

    ans.push_back(S);

    for (int i = 0; i < S.size(); ++i) {
      if (isalpha(S[i])) {
        int sz = ans.size();

        for (int j = 0; j < sz; ++j) {
          string s1 = ans[j];
          string s2 = s1;

          if (islower(s1[i])) {
            s2[i] = toupper(s2[i]);
          } else {
            s2[i] = tolower(s2[i]);
          }

          if (!st.count(s1)) {
            st.insert(s1);
            ans.push_back(s1);
          }

          if (!st.count(s2)) {
            st.insert(s2);
            ans.push_back(s2);
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 88.58%
// Memory Usage: 13.8 MB, less than 52.94%

class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans{""};

    for (const auto& ch : S) {
      int sz = ans.size();

      if (isalpha(ch)) {
        for (int i = 0; i < sz; ++i) {
          ans.push_back(ans[i]);

          ans[i].push_back(tolower(ch));
          ans[i + sz].push_back(toupper(ch));
        }
      } else {
        for (int i = 0; i < sz; ++i) {
          ans[i].push_back(ch);
        }
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 54.55%
// Memory Usage: 11.7 MB, less than 100.00%

class Solution {
  vector<string> ans;

 public:
  vector<string> letterCasePermutation(string S) {
    dfs(S, 0);

    return ans;
  }

  void dfs(string& s, int pos) {
    if (pos == s.size()) {
      ans.push_back(s);

      return;
    }

    if (isalpha(s[pos])) {
      s[pos] = tolower(s[pos]);
      dfs(s, pos + 1);

      s[pos] = toupper(s[pos]);
      dfs(s, pos + 1);
    } else {
      dfs(s, pos + 1);
    }
  }
};
// Runtime: 12 ms, faster than 54.55%
// Memory Usage: 14.6 MB, less than 5.88%