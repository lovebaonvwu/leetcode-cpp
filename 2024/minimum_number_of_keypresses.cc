class Solution {
 public:
  int minimumKeypresses(string s) {
    vector<int> cnt(26);
    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    sort(rbegin(cnt), rend(cnt));
    int ans = 0;
    for (int i = 0, key = 0; i < 26 && cnt[i] > 0; ++i) {
      ans += cnt[i] * (key / 9 + 1);
      ++key;
    }

    return ans;
  }
};
// 15 ms
// 10.85 MB