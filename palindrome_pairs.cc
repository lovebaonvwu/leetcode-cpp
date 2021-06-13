class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_set<string> st;
    unordered_map<string, int> mp;

    for (int i = 0; i < words.size(); ++i) {
      mp[words[i]] = i;
    }

    sort(words.begin(), words.end(),
         [](auto& a, auto& b) { return a.size() < b.size(); });

    vector<vector<int>> ans;

    for (int i = 0; i < words.size(); ++i) {
      string s = words[i];

      for (int k = 0; k <= s.size(); ++k) {
        string s1 = s.substr(0, k);
        string s2 = s.substr(k);

        if (isPalidrome(s1)) {
          string t = s2;

          reverse(t.begin(), t.end());

          if (st.count(t)) {
            ans.push_back({mp[t], mp[s]});
          }
        }

        if (isPalidrome(s2)) {
          string t = s1;

          reverse(t.begin(), t.end());

          if (st.count(t)) {
            ans.push_back({mp[s], mp[t]});
          }
        }
      }

      st.insert(s);
    }

    return ans;
  }

 private:
  bool isPalidrome(const string& s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 208 ms, faster than 71.87%
// Memory Usage: 64.7 MB, less than 57.50%