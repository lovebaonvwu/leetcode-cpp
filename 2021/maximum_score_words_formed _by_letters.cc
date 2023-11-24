class Solution {
 public:
  int maxScoreWords(vector<string>& words,
                    vector<char>& letters,
                    vector<int>& score) {
    vector<int> cnt(26);

    for (auto letter : letters) {
      ++cnt[letter - 'a'];
    }

    return dfs(words, cnt, score, 0);
  }

  int dfs(vector<string>& words, vector<int> cnt, vector<int>& score, int p) {
    if (p == words.size()) {
      return 0;
    }

    vector<int> new_cnt(cnt);

    int getScore = 0;
    bool couldPick = true;

    for (auto ch : words[p]) {
      --new_cnt[ch - 'a'];

      if (new_cnt[ch - 'a'] < 0) {
        couldPick = false;
        break;
      }

      getScore += score[ch - 'a'];
    }

    int res = 0;

    if (couldPick) {
      res = max(res, getScore + dfs(words, new_cnt, score, p + 1));
    }

    res = max(res, dfs(words, cnt, score, p + 1));

    return res;
  }
};
// Runtime: 16 ms, faster than 42.82%
// Memory Usage: 20.6 MB, less than 30.70%