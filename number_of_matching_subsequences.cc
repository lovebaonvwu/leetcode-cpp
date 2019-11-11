class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    vector<const char*> waiting[128];

    for (const auto& w : words) {
      waiting[w[0]].push_back(w.c_str());
    }

    for (const char& c : S) {
      auto next = waiting[c];
      waiting[c].clear();

      for (auto p : next) {
        waiting[*++p].push_back(p);
      }
    }

    return waiting[0].size();
  }
};
// Runtime: 172 ms, faster than 84.77%
// Memory Usage: 40.8 MB, less than 100.00%

class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int ans = 0;

    unordered_set<string> st;

    for (const string& word : words) {
      if (isSubseq(S, word, st)) {
        st.insert(word);
        ++ans;
      }
    }

    return ans;
  }

  bool isSubseq(string& s, const string& word, unordered_set<string>& st) {
    if (st.count(word)) {
      return true;
    }

    int i = 0;
    for (int j = 0; j < s.size() && i < word.size(); ++j) {
      if (s[j] == word[i]) {
        ++i;
      }
    }

    return i == word.size();
  }
};
// Runtime: 1876 ms, faster than 5.01%
// Memory Usage: 27.9 MB, less than 100.00%

class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int ans = 0;

    for (const string& word : words) {
      if (isSubseq(S, word)) {
        ++ans;
      }
    }

    return ans;
  }

  bool isSubseq(string& s, const string& word) {
    int i = 0;
    for (int j = 0; j < s.size() && i < word.size(); ++j) {
      if (s[j] == word[i]) {
        ++i;
      }
    }

    return i == word.size();
  }
};
// Time Limit Exceeded