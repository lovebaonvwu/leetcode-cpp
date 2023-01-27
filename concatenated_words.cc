class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> d(words.begin(), words.end());
    vector<string> ans;

    for (auto& w : words) {
      int n = w.size();
      vector<bool> dp(n + 1);
      dp[0] = true;

      for (int i = 1; i <= n; ++i) {
        for (int j = (i == n ? 1 : 0); j < i; ++j) {
          if (dp[j] && d.count(w.substr(j, i - j))) {
            dp[i] = true;
          }
        }

        if (dp[n]) {
          ans.push_back(w);
        }
      }
    }

    return ans;
  }
};
// Runtime 227 ms
// Memory 42.8 MB
// 2023.1.27 at 茗筑美嘉