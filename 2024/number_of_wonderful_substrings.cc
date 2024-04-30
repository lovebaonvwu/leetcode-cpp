class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long ans = 0;
    int mask = 0;
    vector<int> cnt(1024);
    cnt[0] = 1;

    for (auto c : word) {
      mask ^= 1 << (c - 'a');
      ans += cnt[mask];

      for (int i = 0; i < 10; ++i) {
        ans += cnt[mask ^ (1 << i)];
      }

      ++cnt[mask];
    }

    return ans;
  }
};
// 49 ms
// 16.03 MB