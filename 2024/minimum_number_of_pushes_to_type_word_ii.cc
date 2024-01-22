class Solution {
 public:
  int minimumPushes(string word) {
    vector<int> cnt(26);
    for (auto c : word) {
      ++cnt[c - 'a'];
    }

    sort(rbegin(cnt), rend(cnt));

    int ans = 0;
    int n = cnt.size();
    for (int i = 0; i < n && cnt[i] > 0; ++i) {
      if (i < 8) {
        ans += cnt[i];
      } else if (i < 16) {
        ans += cnt[i] * 2;
      } else if (i < 24) {
        ans += cnt[i] * 3;
      } else {
        ans += cnt[i] * 4;
      }
    }

    return ans;
  }
};
// 66ms
// 27.43MB