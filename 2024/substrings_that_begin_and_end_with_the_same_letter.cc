class Solution {
 public:
  long long numberOfSubstrings(string s) {
    unordered_map<char, int> cnt;
    int n = s.size();

    long long ans = n;

    for (auto c : s) {
      ans += cnt[c];
      ++cnt[c];
    }

    return ans;
  }
};
// 29 ms
// 11.89 MB
