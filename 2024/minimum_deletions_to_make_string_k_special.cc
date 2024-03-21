class Solution {
 public:
  int minimumDeletions(string word, int k) {
    vector<int> cnt(26);
    for (auto c : word) {
      ++cnt[c - 'a'];
    }

    sort(begin(cnt), end(cnt));

    int n = word.size();
    int ans = n;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] == 0)
        continue;

      int removed = 0;
      for (int j = 0; j < 26; ++j) {
        if (i == j)
          continue;
        if (cnt[j] == 0)
          continue;

        if (cnt[i] > cnt[j])
          removed += cnt[j];
        else if (cnt[i] + k <= cnt[j])
          removed += cnt[j] - (cnt[i] + k);
      }

      ans = min(ans, removed);
    }

    return ans;
  }
};
// 42 ms
// 17.35 MB