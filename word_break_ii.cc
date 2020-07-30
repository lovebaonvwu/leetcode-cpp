class Solution {
  unordered_map<string, vector<string>> mem;

 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());

    return dfs(s, st);
  }

  vector<string> dfs(string s, unordered_set<string>& st) {
    vector<string> res;

    if (s.empty()) {
      return res;
    }

    if (mem.count(s)) {
      return mem[s];
    }

    if (st.count(s)) {
      res.push_back(s);
    }

    for (int i = 1; i < s.size(); ++i) {
      string tail = s.substr(i);

      if (st.count(tail)) {
        auto heads = dfs(s.substr(0, i), st);

        for (auto& head : heads) {
          res.push_back(head + " " + tail);
        }
      }
    }

    mem[s] = res;

    return res;
  }
};
// Runtime: 16 ms, faster than 85.79%
// Memory Usage: 12 MB, less than 56.30%