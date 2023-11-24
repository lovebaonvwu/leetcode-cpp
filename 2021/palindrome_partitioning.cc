class Solution {
  vector<vector<string>> ans;

  bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }

 public:
  vector<vector<string>> partition(string s) {
    dfs(s, {}, 0);

    return ans;
  }

  void dfs(string& s, vector<string> t, int i) {
    if (i == s.size()) {
      ans.push_back(t);
      return;
    }

    for (int j = i; j < s.size(); ++j) {
      string sub = s.substr(i, j - i + 1);

      if (isPalindrome(sub)) {
        t.push_back(sub);

        dfs(s, t, j + 1);

        t.pop_back();
      }
    }
  }
};
// Runtime: 332 ms, faster than 5.02%
// Memory Usage: 163.4 MB, less than 5.10%

class Solution {
  vector<vector<string>> ans;

 public:
  vector<vector<string>> partition(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if ((s[j] == s[i]) && (i - j <= 2 || dp[j + 1][i - 1])) {
          dp[j][i] = true;
        }
      }
    }

    dfs(s, dp, {}, 0);

    return ans;
  }

  void dfs(string& s, vector<vector<bool>>& dp, vector<string> t, int i) {
    if (i == s.size()) {
      ans.push_back(t);
      return;
    }

    for (int j = i; j < s.size(); ++j) {
      if (dp[i][j]) {
        t.push_back(s.substr(i, j - i + 1));

        dfs(s, dp, t, j + 1);

        t.pop_back();
      }
    }
  }
};
// Runtime: 344 ms, faster than 5.02%
// Memory Usage: 163.6 MB, less than 5.10%