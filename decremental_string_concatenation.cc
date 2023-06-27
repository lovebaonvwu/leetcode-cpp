class Solution {
  int dp[1001][26][26] = {0};
  int dfs(const vector<string>& words, int i, char head, char tail) {
    if (i == words.size()) {
      return 0;
    }

    if (dp[i][head - 'a'][tail - 'a'] > 0) {
      return dp[i][head - 'a'][tail - 'a'];
    }

    int cnt1 = words[i].size() + dfs(words, i + 1, words[i][0], tail);
    if (words[i].back() == head) {
      cnt1 -= 1;
    }

    int cnt2 = words[i].size() + dfs(words, i + 1, head, words[i].back());
    if (words[i][0] == tail) {
      cnt2 -= 1;
    }

    return dp[i][head - 'a'][tail - 'a'] = min(cnt1, cnt2);
  }

 public:
  int minimizeConcatenatedLength(vector<string>& words) {
    return words[0].size() + dfs(words, 1, words[0][0], words[0].back());
  }
};
// Runtime 208 ms
// Memory 40.8 MB