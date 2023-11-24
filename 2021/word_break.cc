class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    vector<bool> dp(s.size() + 1, false);

    for (auto& word : wordDict) {
      dict.insert(word);
    }

    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (dp[j]) {
          string sub = s.substr(j, i - j);

          if (dict.find(sub) != dict.end()) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[s.size()];
  }
};  // 4ms

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, int> mp;

    for (auto& word : wordDict) {
      mp[word] = 1;
    }

    return dfs(s, 0, mp);
  }

  bool dfs(string& s, int pos, unordered_map<string, int>& mp) {
    if (pos == s.size()) {
      return true;
    }

    string word = "";
    for (int i = pos; i < s.size(); ++i) {
      word += s[i];

      if (mp[word]) {
        if (dfs(s, i + 1, mp)) {
          return true;
        }
      }
    }

    return false;
  }
};  // Time Limit Exceeded