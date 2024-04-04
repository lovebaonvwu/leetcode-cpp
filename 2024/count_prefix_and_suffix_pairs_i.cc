class Solution {
  bool isPrefix(const string& prefix, const string& s) {
    for (int i = 0; i < prefix.size(); ++i) {
      if (prefix[i] != s[i])
        return false;
    }

    return true;
  }

  bool isSuffix(const string& suffix, const string& s) {
    for (int i = 0; i < suffix.size(); ++i) {
      if (suffix[suffix.size() - i - 1] != s[s.size() - i - 1])
        return false;
    }

    return true;
  }

  bool isPrefixAndSuffix(const string& a, const string& s) {
    return isPrefix(a, s) && isSuffix(a, s);
  }

 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int ans = 0;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans += isPrefixAndSuffix(words[i], words[j]);
      }
    }

    return ans;
  }
};
// 0 ms
// 23.12 MB
